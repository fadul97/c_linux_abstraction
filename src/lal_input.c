#include "lal/lal_input.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Keyboard
{
	b8 keys[256];
} Keyboard;

typedef struct Mouse
{
	sshort16 x;
	sshort16 y;
} Mouse;

typedef struct InputState
{
	Keyboard keyboard_current;
	Keyboard keyboard_previous;
	Mouse mouse_current;
	Mouse mouse_previous;
} InputState;

static InputState *input_state;

void input_initialize()
{
	input_state = malloc(sizeof(InputState));	

	for(int i = 0; i < 256; i++)
	{
		input_state->keyboard_current.keys[i] = FALSE;
		input_state->keyboard_previous.keys[i] = FALSE;
	
	}
}

b8 is_key_down(Keys key)
{
	if(!input_state)
		return FALSE;

	return input_state->keyboard_current.keys[key] == TRUE;
}

b8 was_key_down(Keys key)
{
	if(!input_state)
		return FALSE;

	return input_state->keyboard_previous.keys[key] == TRUE;
}

b8 is_key_up(Keys key)
{
	if(!input_state)
		return TRUE;

	return input_state->keyboard_current.keys[key] == FALSE;
}

b8 was_key_up(Keys key)
{
	if(!input_state)
		return TRUE;

	return input_state->keyboard_current.keys[key] == FALSE;
}

void input_process_key(Keys key, b8 pressed)
{
	if(input_state && input_state->keyboard_current.keys[key] != pressed)
		input_state->keyboard_current.keys[key] = pressed;
}

void input_update()
{
	for(int i = 0; i < 256; i++)
		input_state->keyboard_previous.keys[i] = input_state->keyboard_current.keys[i];
}
