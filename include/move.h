#ifndef MOVE_H
#define MOVE_H

struct Move
{
	// move coordinates
	std::uint8_t from;
	std::uint8_t to;

	// used to specify promotions
	std::uint8_t promotion;

    // unsigned 8-bit int used for cache performance as it reduces move size; 
    // int is 4 bytes (32 bits)
    // uint8_t 1 byte (8 bits)
};

#endif

// struct is in its own independent file as it is used by board, controller, and my eval.