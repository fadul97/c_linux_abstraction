#ifndef LAL_INPUT_H
#define LAL_INPUT_H

#include "lal_defines.h"

#if LPLATFORM_LINUX

typedef enum Buttons
{
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_MIDDLE
} Buttons;

typedef enum Keys
{
		// Backspace key
    KEY_BACKSPACE = 0x08,

    // Enter key
    KEY_ENTER = 0x0D,

    // Tab key
    KEY_TAB = 0x09,
    
    // Shift key    
    KEY_SHIFT = 0x10,

    // Ctrl(Control) key
    KEY_CONTROL = 0x11,

    // Pause key
    KEY_PAUSE = 0x13,

    // Capslock key
    KEY_CAPITAL = 0x14,

    // Escape key;
    KEY_ESCAPE = 0x1B,

    KEY_CONVERT = 0x1C,
    KEY_NONCONVERT = 0x1D,
    KEY_ACCEPT = 0x1E,
    KEY_MODECHANGE = 0x1F,

    // Space key
    KEY_SPACE = 0x20,

    // Page up key
    KEY_PAGEUP = 0x21,

    // Page down key
    KEY_PAGEDOWN = 0x22,

    // End key
    KEY_END = 0x23,

    // Home key
    KEY_HOME = 0x24,

    // Left arrow key
    KEY_LEFT = 0x25,

    // Up arrow key
    KEY_UP = 0x26,

    // Right arrow key
    KEY_RIGHT = 0x27,

    // Down arrow key
    KEY_DOWN = 0x28,
    
    // Select key
    KEY_SELECT = 0x29,
    
    // Print key
    KEY_PRINT = 0x2A,

    // Execute key
    KEY_EXECUTE = 0x2B,

    // Print screen key
    KEY_PRINTSCREEN = 0x2C,

    // Insert key
    KEY_INSERT = 0x2D,
    
    // Delete key
    KEY_DELETE = 0x2E,
    
    // Help key
    KEY_HELP = 0x2F,

    // 0 key
    KEY_0 = 0x30,
    
    // 1 key
    KEY_1 = 0x31,
    
    // 2 key
    KEY_2 = 0x32,

    // 3 key
    KEY_3 = 0x33,

    // 4 key
    KEY_4 = 0x34,

    // 5 key
    KEY_5 = 0x35,

    // 6 key
    KEY_6 = 0x36,

    // 7 key
    KEY_7 = 0x37,

    // 8 key
    KEY_8 = 0x38,

    // 9 key
    KEY_9 = 0x39,

    // A key
    KEY_A = 0x41,

    // B key
    KEY_B = 0x42,

    // C key
    KEY_C = 0x43,

    // D key
    KEY_D = 0x44,

    // E key
    KEY_E = 0x45,
    
    // F key
    KEY_F = 0x46,
    

    // G key
    KEY_G = 0x47,
    
    // H key
    KEY_H = 0x48,
    
    // I key
    KEY_I = 0x49,
    
    // J key
    KEY_J = 0x4A,
    
    // K key
    KEY_K = 0x4B,
    
    // L key
    KEY_L = 0x4C,
    
    // M key
    KEY_M = 0x4D,
    
    // N key
    KEY_N = 0x4E,
    
    // O key
    KEY_O = 0x4F,
    
    // P key
    KEY_P = 0x50,
    
    // Q key
    KEY_Q = 0x51,
    
    // R key
    KEY_R = 0x52,
    
    // S key
    KEY_S = 0x53,
    
    // T key
    KEY_T = 0x54,
    
    // U key
    KEY_U = 0x55,
    
    // V key
    KEY_V = 0x56,
    
    // W key
    KEY_W = 0x57,
    
    // X key
    KEY_X = 0x58,
    
    // Y key
    KEY_Y = 0x59,
    
    // Z key
    KEY_Z = 0x5A,

    // Left Windows/Super key
    KEY_LSUPER = 0x5B,

    // Right Windows/Super key
    KEY_RSUPER = 0x5C,
    
    // Applicatons key
    KEY_APPS = 0x5D,

    // Sleep key
    KEY_SLEEP = 0x5F,

    // Numberpad 0 key
    KEY_NUMPAD0 = 0x60,
    
    // Numberpad 1 key
    KEY_NUMPAD1 = 0x61,
    
    // Numberpad 2 key
    KEY_NUMPAD2 = 0x62,
    
    // Numberpad 3 key
    KEY_NUMPAD3 = 0x63,
    
    // Numberpad 4 key
    KEY_NUMPAD4 = 0x64,
    
    // Numberpad 5 key
    KEY_NUMPAD5 = 0x65,
    
    // Numberpad 6 key
    KEY_NUMPAD6 = 0x66,
    
    // Numberpad 7 key
    KEY_NUMPAD7 = 0x67,
    
    // Numberpad 8 key
    KEY_NUMPAD8 = 0x68,
    
    // Numberpad 9 key
    KEY_NUMPAD9 = 0x69,
    
    // Numberpad multiply key
    KEY_MULTIPLY = 0x6A,
    
    // Numberpad add key
    KEY_ADD = 0x6B,
    
    // Numberpad separator key
    KEY_SEPARATOR = 0x6C,
    
    // Numberpad subtract key
    KEY_SUBTRACT = 0x6D,
    
    // Numberpad decimal key
    KEY_DECIMAL = 0x6E,
    
    // Numberpad divide key
    KEY_DIVIDE = 0x6F,

    // F1 key
    KEY_F1 = 0x70,
    
    // F2 key
    KEY_F2 = 0x71,
    
    // F3 key
    KEY_F3 = 0x72,
    
    // F4 key
    KEY_F4 = 0x73,
    
    // F5 key
    KEY_F5 = 0x74,
    
    // F6 key
    KEY_F6 = 0x75,
    
    // F7 key
    KEY_F7 = 0x76,
    
    // F8 key
    KEY_F8 = 0x77,
    
    // F9 key
    KEY_F9 = 0x78,
    
    // F10 key
    KEY_F10 = 0x79,
    
    // F11 key
    KEY_F11 = 0x7A,
    
    // F12 key
    KEY_F12 = 0x7B,
    
    // F13 key
    KEY_F13 = 0x7C,
    
    // F14 key
    KEY_F14 = 0x7D,
    
    // F15 key
    KEY_F15 = 0x7E,
    
    // F16 key
    KEY_F16 = 0x7F,
    
    // F17 key
    KEY_F17 = 0x80,
    
    // F18 key
    KEY_F18 = 0x81,
    
    // F19 key
    KEY_F19 = 0x82,
    
    // F20 key
    KEY_F20 = 0x83,
    
    // F21 key
    KEY_F21 = 0x84,
    
    // F22 key
    KEY_F22 = 0x85,
    
    // F23 key
    KEY_F23 = 0x86,
    
    // F24 key
    KEY_F24 = 0x87,

    // Number lock key
    KEY_NUMLOCK = 0x90,

    // Scroll lock key
    KEY_SCROLL = 0x91,

    // Numberpad equal key
    KEY_NUMPAD_EQUAL = 0x92,

    // Left shift key
    KEY_LSHIFT = 0xA0,
    
    // Right shift key
    KEY_RSHIFT = 0xA1,
    
    // Left control key
    KEY_LCONTROL = 0xA2,
    
    // Right control key
    KEY_RCONTROL = 0xA3,
    
    // Left alt key
    KEY_LALT = 0xA4,
    
    // Right alt key
    KEY_RALT = 0xA5,

    // Semicolon key
    KEY_SEMICOLON = 0x3B,

    // Apostrophe/single-quote key
    KEY_APOSTROPHE = 0xDE,
    
    // An alias for KEY_APOSTROPHE, apostrophe/single-quote key
    KEY_QUOTE = KEY_APOSTROPHE,
    
    // Equal/plus key
    KEY_EQUAL = 0xBB,
    
    // Comma key
    KEY_COMMA = 0xBC,
    
    // Minus key
    KEY_MINUS = 0xBD,
    
    // Period key
    KEY_PERIOD = 0xBE,
    
    // Slash key
    KEY_SLASH = 0xBF,

    // Grave key
    KEY_GRAVE = 0xC0,

    // Left (square) bracket key '[{'
    KEY_LBRACKET = 0xDB,
    
    // Pipe/backslash key
    KEY_PIPE = 0xDC,
    
    // An alias for pipe/backslash key
    KEY_BACKSLASH = KEY_PIPE,
    
    // Right (square) bracket key ']}'
    KEY_RBRACKET = 0xDD,
} Keys;

void input_initialize();

b8 is_key_down(Keys key);
b8 was_key_down(Keys key);

b8 is_key_up(Keys key);
b8 was_key_up(Keys key);

void input_process_key(Keys key, b8 pressed);

void input_update();

#endif // LPLATFORM_LINUX

#endif // LAL_INPUT_H
