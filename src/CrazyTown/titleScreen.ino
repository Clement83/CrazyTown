const byte logo[] PROGMEM = {64,36,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xE0,0x0,0x78,0x0,0x0,0x0,0x0,0xE,0x78,0x0,0xE0,0x0,0x0,0x0,0x0,0x1C,0x18,0x0,0xE0,0x0,0x0,0x0,0x0,0x18,0x1D,0x8F,0xF0,0x0,0x0,0x0,0x0,0x18,0xD,0x8E,0xE0,0x0,0x0,0x0,0x0,0x18,0xD,0x8E,0xE0,0x0,0x0,0x0,0x0,0x18,0xD,0x8E,0xE0,0x0,0x0,0x0,0x0,0x18,0xD,0x8E,0xE0,0x0,0x0,0x0,0x0,0x18,0x1D,0x8E,0xE7,0xFE,0x70,0x60,0xEC,0x1C,0x19,0xCE,0xE0,0x60,0x78,0x71,0xCC,0xE,0x79,0xDE,0xE0,0x60,0xF8,0x39,0x8C,0x7,0xE0,0xFE,0xE0,0x60,0xD8,0x1B,0xC,0x0,0x0,0x0,0x0,0x60,0xDC,0x1F,0xC,0x0,0x0,0x0,0x0,0x61,0xCC,0xE,0xC,0x7,0x0,0x0,0x0,0x61,0x8E,0xE,0xC,0x1,0xFC,0x0,0x0,0x61,0xFE,0x1F,0xC,0x7,0x76,0x3C,0x0,0x63,0x86,0x3B,0x8C,0x0,0xDE,0x35,0x0,0x63,0x7,0x31,0x8C,0x1,0xD0,0x1D,0x80,0x67,0x3,0x71,0xCC,0x0,0x3F,0x90,0x60,0x66,0x3,0xE0,0xEC,0x0,0x2C,0x9C,0x30,0x0,0x0,0x0,0x0,0x0,0x6E,0x9E,0x98,0x0,0x0,0x0,0x0,0x0,0xFF,0xD3,0xFF,0xC0,0x0,0x0,0x0,0x3,0x80,0x7E,0x0,0x30,0x0,0x0,0x0,0x6,0x20,0x81,0x0,0x10,0x0,0x0,0x0,0xC,0x0,0xE1,0x0,0x70,0x0,0x0,0x0,0x8,0x20,0x81,0x7F,0xC0,0x0,0x0,0x0,0x1B,0xFF,0x81,0xBD,0x80,0x0,0x0,0x0,0x33,0xFF,0x81,0xFE,0x80,0x0,0x0,0x0,0x3C,0xCC,0xFF,0x66,0x0,0x0,0x0,0x0,0x0,0xCC,0x0,0x66,0x0,0x0,0x0,0x0,0x0,0xFC,0x0,0x7E,0x0,0x0,0x0,0x0,0x0,0x78,0x0,0x3C,0x0,0x0,0x0,0x0,};

void drawTitleScreen(){
  gb.titleScreen(logo);
  gb.pickRandomSeed(); //pick a different random seed each time for games to be different
}
