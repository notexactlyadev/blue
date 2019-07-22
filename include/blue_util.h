#pragma once
#include <iostream>
#include <type_traits>
#include <cstdint>

template <class T, const uint64_t type_size = (sizeof(std::decay_t<T>) * 8), class = std::enable_if_t<std::is_floating_point_v<std::decay_t<T>> ||
std::is_integral_v<std::decay_t<T>>>>
inline void print_bits(T&& variable) {

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

	/* Ugly hack, I know */
	auto casted = *reinterpret_cast<std::make_signed_t<std::remove_reference_t<T>>*>(&variable);

	std::cout << "-> " << casted << " (decimal)\n";
}

