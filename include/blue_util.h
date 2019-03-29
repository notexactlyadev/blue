#pragma once
#include <iostream>
#include <type_traits>
#include <cstdint>

// #define PRINT_BITS_EXTRA 1

template <class T, const uint64_t type_size = (sizeof(std::decay_t<T>) * 8), class = std::enable_if_t<std::is_floating_point_v<std::decay_t<T>> ||
std::is_integral_v<std::decay_t<T>>>>
inline void print_bits(T&& variable) {
	#ifdef PRINT_BITS_EXTRA
	std::printf("Ejecutando funcion (%s): \n", __PRETTY_FUNCTION__);
	#endif
	/*
	Nuestra mascara consiste en una variable de 64 bits, que contiene un solo bit activado correspondiente
	al tamaño de T en bits, mientras mascara no sea 0, continuamos, al finalizar, movemos el bit de la variable
	a la derecha un solo lugar.

	Un 1 siempre es un entero literal de 32 bits, uno de los raros casos donde debemos convertir un entero literal a
	64 bits.
	*/
	size_t counter = 0;
	for (auto mascara = static_cast<decltype(type_size)>(1) << (type_size - 1); mascara; mascara >>= 1, ++counter) {
		/* usando & hacemos AND, en caso de coincidir (verdadero y verdadero), imprimimos true, en caso contrario, false */
		std::cout << static_cast<bool>(variable & mascara) /*? 1 : 0)*/;
		if (!(counter % 3)) {
			std::cout << " ";
		}
	}
	std::cout << "-> " << variable << " in decimal\n";
}


// template <typename T>
// void print_bits(T x) {
//   T orig = x;
//   size_t wl = sizeof(T) * 8 - 1;
//   unsigned mask;
//   for (mask = 1 << wl; mask; mask >>= 1) {
//     printf("%c", (x & mask ? '1' : '0'));
//   }
//   printf(" -> %d in decimal\n", orig);
// }