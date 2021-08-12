#pragma once

namespace decode
{
	void coding(int* dvoich, int dv_length, int * swap_index, int index_count, bool write, std::string* path);
	void decoding(int * swap_index, int index_count, std::string* path);
	void clean(std::string * path);
}
