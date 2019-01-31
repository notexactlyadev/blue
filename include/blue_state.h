#pragma once
#include <cstdint>

namespace blue::state {
	struct sequencer_t {
	bool stopped;
	bool working;
	bool search;
	bool exec;

	void togglestate();
	};
} // blue::state
