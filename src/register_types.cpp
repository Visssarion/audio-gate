#include "register_types.h"
#include "audio_effect_gate.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_gate();
void uninitialize_gate();


void initialize_gate_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SERVERS) {
		return;
	}

	ClassDB::register_class<AudioEffectGate>();
	ClassDB::register_class<AudioEffectGateInstance>();
}

void uninitialize_gate_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SERVERS) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT gate_effect_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_gate_module);
	init_obj.register_terminator(uninitialize_gate_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SERVERS);

	return init_obj.init();
}
}
// GDREGISTER_CLASS(AudioEffectGate);

