#define LAUNCH_PROGRAM 21

if (record->event.pressed && keycode >= 0x8000) {
        uint8_t reply[32] = {0};

        if (keycode < 0x8100)
        {
            reply[0] = LAUNCH_PROGRAM;
            reply[1] =  keycode - 0x8000;
            raw_hid_send(reply, 32);
        }
        return false;
    }
