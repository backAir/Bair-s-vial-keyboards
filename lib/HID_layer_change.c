#define LAYER_CHANGE 20

switch (data[0]) {
        case LAYER_CHANGE:
            layer_move(data[1]);
            break;
    }
    raw_hid_send(data, 32);
