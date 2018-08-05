#include <iostream>
#include "file_huffman.h"
#include "file_reader.h"

bool compare_files(std::string const &file1, std::string const &file2) {
    bool eq = true;
    file_reader reader1(file1);
    file_reader reader2(file2);
    for (uint64_t i = 0; reader1.has_next() && reader2.has_next(); i++) {
        unsigned char ch1 = reader1.next(), ch2 = reader2.next();
        if (ch1 != ch2) {
            eq = false;
            /*std::cout << "error: \"" << i << "\" byte - file1 \"" <<
                      static_cast<uint32_t>(ch1) << "\", file2 \"" <<
                      static_cast<uint32_t>(ch2) << "\"" << std::endl;
            */
        }
    }
    if (reader1.has_next() != reader2.has_next()) {
        eq = false;
        //std::cout << "error: file have different length" << std::endl;
    }
    reader1.close();
    reader2.close();
    if (!eq) {
        std::cout << "error: files \"" << file1 << "\" and \"" << file2 << "\" are not equal" << std::endl;
    }
    return eq;
}

bool test(std::string fileName, std::string format) {
    std::cout << "test " << fileName << format << std::endl;
    compr_or_decompr_file(true, fileName + format, fileName + "_compressed" + format);
    compr_or_decompr_file(false, fileName + "_compressed" + format, fileName + "_decompressed" + format);
    if (compare_files(fileName + format, fileName + "_decompressed" + format)) {
        std::cout << "correct" << std::endl;
    } else {
        std::cout << "wrong" << std::endl;
    }
    std::cout << "________________________\n" << std::endl;
}

int main() {

    test("test", ".zip");
    test("tenzors", ".zip");

    return 0;
}