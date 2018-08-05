#include <iostream>
#include <vector>
#include "file_huffman.h"
#include "../huffman/huffman.h"
#include "file_reader.h"
#include "file_writer.h"

void compr_or_decompr_file(bool compr_or_decompr, std::string const &from, std::string const &to) {
    file_reader reader(from);
    file_writer writer(to);
    huffman huf;
    if (compr_or_decompr) {
        huf.count(reader);
        reader.close();
        reader.open(from);
        huf.compress(reader, writer);
    } else {
        huf.decompress(reader, writer);
    }
    reader.close();
    writer.close();
}