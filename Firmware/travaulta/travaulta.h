#pragma once

#include "quantum.h"
#include "ec_switch_matrix.h"

#define XXX KC_NO

enum ec_keycodes {
    EC_AP_I = QK_KB_0,  // Increases actuation point (more travel)
    EC_AP_D,            // Decreases actuation point
    EC_CLR              // Reset EC config
};

// clang-format off
#define LAYOUT( \
	k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k3B, k3C, k3D, k3F, k3H, k3I \
) { \
	{k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K}, \
	{k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, XXX}, \
	{k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, XXX}, \
	{XXX, k3B, k3C, k3D, XXX, k3F, XXX, k3H, k3I, XXX, XXX} \
}

// clang-format on
