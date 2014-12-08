
//store the different sprites in PROGMEM to save RAM

//sprite 0
const byte Eau[] PROGMEM = {16,16,0xFF,0xFF,0xFF,0xFF,0xFF,0xFD,0xF7,0xFA,0xEB,0xFF,0xFF,0xDF,0xFF,0xAF,0xFF,0xFF,0xFF,0xFF,0xFB,0xFF,0xF5,0xFF,0xFF,0xDF,0xFF,0xAF,0xDF,0xFF,0xAF,0xFF,0xFF,0xFF,};
//sprite 1
const byte Fleure[] PROGMEM = {16,16,0x0,0x0,0x50,0x0,0x20,0x28,0x50,0x10,0x0,0x28,0x0,0x0,0x0,0x0,0x1,0x40,0x0,0x80,0x1,0x40,0x0,0x0,0x0,0x14,0x28,0x8,0x10,0x14,0x28,0x0,0x0,0x0,};
//sprite 2
const byte Foret[] PROGMEM = {16,16,0x0,0x0,0x10,0x0,0x6D,0x0,0x54,0x8,0xAA,0x14,0x54,0x8,0x6C,0x20,0x10,0x0,0x0,0x10,0x0,0x6C,0x4,0x54,0x10,0xAA,0x28,0x54,0x10,0x6C,0x0,0x10,0x0,0x0,};
//sprite 3
const byte Pavillon[] PROGMEM = {16,16,0x0,0x0,0x7F,0xFE,0x6B,0x56,0x57,0xAA,0x7F,0xFE,0x6B,0x56,0x57,0xAA,0x7F,0xFE,0x6B,0x56,0x57,0xAA,0x7F,0xFE,0x40,0x2,0x40,0x2,0x40,0x2,0x7F,0xFE,0x0,0x0,};
//sprite 4
const byte RoofTop[] PROGMEM = {16,16,0x0,0x0,0x7F,0xFE,0x60,0x6,0x5F,0xFA,0x50,0xA,0x52,0xA,0x50,0x4A,0x50,0xA,0x50,0xA,0x56,0x2A,0x56,0xA,0x50,0xA,0x5F,0xFA,0x60,0x6,0x7F,0xFE,0x0,0x0,};
//sprite 5
const byte Usine[] PROGMEM = {16,16,0x0,0x0,0x38,0x0,0x7D,0xFE,0x7D,0x2,0x7D,0x2,0x39,0xFE,0x7F,0x2,0x40,0x2,0x40,0x2,0x40,0x2,0x7F,0xFE,0x2,0x0,0x25,0x3C,0x52,0x3C,0x20,0x0,0x0,0x0,};
//sprite 6
const byte Usine2[] PROGMEM = {16,16,0x0,0x20,0x0,0x50,0x38,0x20,0x47,0xFE,0x55,0x2,0x44,0x82,0x38,0xF2,0x21,0xA,0x12,0x66,0xA,0x96,0x6,0x96,0x76,0x66,0x75,0xA,0x4,0xF2,0x7,0xFE,0x0,0x0,};



const byte * GetSpriteById(byte idSprite)
{
  switch(idSprite)
  {
    case 0 :
    return Eau;
    break;
    case 1 :
    return Fleure;
    break;
    case 2 :
    return Foret;
    break;
    case 3 :
    return Pavillon;
    break;
    case 4 :
    return RoofTop;
    break;
    case 5 :
    return Usine2;
    break;
    case 6 :
    return Usine;
    break;
  }
}

#define NB_ZONE 8
//x1,y1, x2 ,y2, tuile
const byte Zones[NB_ZONE*5] PROGMEM = 
{
  0,0,127,31,3,
  0,32,32,62,0,
  47,94,86,116,0,
  42,35,93,57,5,
  14,62,113,93,6,
  98,35,110,44,3,
  111,49,119,60,3,
  47,94,127,127,4,
};





#define WORLD_W 128
#define WORLD_H 128
const byte world[(WORLD_W/8)*WORLD_H] PROGMEM = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x8F,0xFF,0xFF,0xFF,0x80,0x0,0x7F,0xFF,0xE0,0x0,0x0,0x7,0xE0,0xFF,0xFF,0xFF,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7B,0xDD,0xE7,0xEE,0x0,0x0,0xFF,0xFD,0xFF,0xC0,0x0,0x1F,0xFE,0x0,0x0,0x7,0x7B,0xDD,0xE7,0xEF,0x0,0x7E,0xFF,0xF9,0xFF,0x8F,0xE7,0x80,0x3E,0x7F,0xF3,0xE7,0x7B,0xDD,0xE7,0xEF,0x7F,0x7E,0xFF,0xFB,0xFF,0x1F,0xE7,0x80,0x30,0x7F,0xF3,0xE7,0x0,0x1,0xE7,0xE0,0x7F,0x7E,0xFF,0xFB,0xFE,0x3F,0xE7,0xFF,0x30,0x7F,0xF3,0xE7,0x7B,0xDD,0xE7,0xFF,0xFF,0x7E,0xFF,0xFB,0xFC,0x7F,0xE7,0xFF,0x33,0x7F,0xF3,0xE7,0x7B,0xDD,0xE0,0x3F,0xFF,0x7C,0xFF,0xFB,0xF8,0xE0,0x7,0xFF,0x33,0x7F,0xF3,0xE7,0x7B,0xDD,0xE7,0x80,0xFF,0x1,0xFF,0xFB,0xF1,0xC7,0xE7,0xC0,0x33,0x7F,0xF3,0xE7,0x0,0x1,0xE7,0xBE,0xFF,0x7F,0xFF,0xFB,0xE3,0x8F,0xE7,0xDF,0x33,0x60,0x23,0xE7,0xFF,0xFF,0xE7,0xBE,0xFF,0x7F,0xFF,0xFB,0xE7,0x1F,0xE7,0xDF,0x33,0x6F,0x83,0xE7,0x0,0x0,0xE0,0x3E,0xFF,0x7E,0xF,0xFB,0xE6,0x3F,0xE7,0xDF,0x33,0x6F,0x87,0xE7,0x0,0x0,0xE7,0xFE,0xFF,0x7C,0x7,0xFB,0xE4,0x0,0x3,0xDF,0x33,0x6F,0xBF,0xE7,0x3F,0x9E,0x67,0xFE,0xFE,0x78,0x3,0xE0,0xE0,0xDB,0xD8,0x1F,0x33,0x6F,0xBF,0xE7,0x3F,0x1F,0x60,0x3E,0xFC,0xF0,0x3,0xE0,0xE1,0xDB,0xDB,0xC0,0x0,0x0,0x0,0x0,0x3E,0x3F,0x67,0x80,0x1,0xE0,0x43,0xE4,0xE7,0xD9,0x9B,0xFF,0x3,0xF8,0x0,0x0,0x7C,0x7F,0x67,0xBF,0xFF,0xC0,0xC3,0xE0,0xE7,0xD9,0x9B,0xFF,0xCF,0xF9,0xFF,0xFF,0xF8,0xFF,0x60,0x3F,0xFF,0x81,0xC3,0xE0,0xE7,0xDD,0xBB,0xFF,0xCE,0x1,0xFF,0xC0,0x1,0xFF,0x67,0xFF,0xFF,0x3,0xC3,0xFB,0xE7,0xDD,0xBB,0xFC,0x0,0xF9,0xFF,0xC0,0x3,0xFF,0x67,0xFF,0xFE,0x7,0xC3,0xFB,0xE7,0xC0,0x3,0xF8,0xF,0xF9,0xFF,0xCF,0xFF,0xFF,0x7,0xFF,0xFE,0xF,0xC3,0xFB,0xE7,0xFC,0xFF,0xF0,0xFF,0xF8,0x0,0xF,0xFF,0xFF,0xD3,0x0,0x0,0x1F,0xC3,0xFB,0xE7,0xFC,0xFF,0xF3,0xFF,0xF8,0x0,0xF,0xFF,0xFF,0xD0,0x0,0x0,0x3F,0xC3,0xFB,0xE7,0xFC,0xFF,0xF3,0xFF,0xF9,0xFF,0xE7,0xFF,0xFF,0xD0,0x78,0x0,0x7F,0xC3,0xF8,0x7,0xFC,0xFF,0xF3,0xFF,0xF9,0xFF,0xF7,0xFF,0xFF,0xDC,0xF8,0x0,0xFF,0xC3,0xFB,0xE7,0xFC,0xFF,0xF2,0x0,0x0,0x0,0x0,0x0,0x0,0x4,0xF9,0xFF,0xFF,0xC3,0xE3,0xE3,0xFC,0xFF,0xF2,0x0,0x0,0x0,0x0,0x0,0x0,0x4,0xF1,0xFF,0xFF,0xC3,0x8F,0xF3,0xFC,0xFF,0xF2,0x7F,0xFF,0xFE,0xFC,0xFF,0xFF,0xE4,0xE3,0xFF,0xFF,0xC3,0xBF,0xF1,0xFC,0xFF,0xF2,0x7F,0xF0,0x0,0xFC,0xFF,0xFF,0xE4,0x87,0xFF,0xFF,0xC3,0xBF,0xF8,0xFC,0xFF,0xF2,0x7F,0xF7,0xFF,0x8C,0xFF,0xE0,0x64,0x1F,0xFF,0xFF,0xC3,0x9F,0xFC,0x7C,0xFF,0xF2,0x7F,0xF7,0xFF,0xAC,0x0,0x0,0x64,0x3F,0xFF,0xFF,0xC3,0xDF,0xFE,0x0,0x0,0x2,0x0,0x7,0x1,0xA4,0x0,0x6,0x64,0xFF,0xFF,0xFF,0xC3,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xB7,0xEF,0xFE,0x64,0xF8,0x1,0xFF,0xC7,0xFF,0xFF,0xE7,0xFF,0xB0,0x7F,0x70,0x39,0xB0,0x0,0x2,0x64,0xF0,0x0,0x7F,0xC7,0xFF,0xFF,0xC7,0xFF,0xB6,0x41,0x7F,0x39,0x9F,0xBF,0xFA,0x4,0xE3,0xFC,0x7F,0xC7,0xFF,0xFF,0x8F,0xFF,0xB6,0x5D,0x0,0x38,0x1C,0x3F,0x8A,0x4,0xE7,0xFE,0x7F,0xC7,0xFF,0xFF,0x1F,0xFF,0xB6,0x5D,0x0,0x38,0x1,0x0,0x22,0x64,0xCF,0xFE,0x7F,0xC7,0xFF,0xFE,0x3F,0xFF,0xB6,0x5D,0x3F,0x3F,0xFB,0xEF,0xBE,0x64,0xCF,0xFE,0x7F,0x87,0xFF,0xFC,0x7F,0xFF,0xB2,0x51,0x3E,0x0,0xFA,0x2F,0xBE,0x64,0xCC,0x6,0x7F,0x87,0xFF,0xF8,0xFF,0xFF,0xBA,0x51,0x3E,0x7E,0xF8,0xAF,0xBE,0x64,0xCD,0x56,0x7F,0x87,0xFF,0xF1,0xFF,0xFF,0xBA,0x51,0x3E,0x7E,0xFD,0xAF,0x80,0x64,0xCD,0x56,0x7F,0xF,0xFF,0xE3,0xFF,0xFF,0xBA,0x5F,0x3E,0x70,0x1,0x8F,0x80,0x64,0xC5,0x56,0x3F,0xF,0xFF,0xC3,0xFF,0xFF,0xBA,0x5F,0x3E,0x70,0x0,0x0,0x3F,0xE4,0xE5,0x57,0x1E,0xF,0xFF,0xC3,0xFF,0xFF,0x8A,0x40,0x3E,0x73,0xFF,0xFF,0xFF,0xE4,0xE0,0x7,0x84,0xF,0xFF,0xC3,0xFF,0xFF,0xAA,0x40,0x3E,0x3,0xFF,0xE0,0x0,0x4,0xE1,0xFF,0xC0,0x1F,0xFF,0xC3,0xFF,0xFF,0xAA,0x7F,0xBE,0x3,0xFF,0xE0,0x0,0x4,0xF0,0xFF,0xE0,0x1F,0xFF,0xC3,0xFF,0xFF,0xAA,0x7F,0xBF,0xF0,0x7,0xE7,0xEE,0xFC,0xFC,0x3F,0xFC,0x1F,0xFF,0xC3,0xFF,0xFF,0xAA,0x7F,0xBF,0xFF,0xF7,0xE7,0xEE,0x0,0xFE,0xF,0xFE,0x1F,0xFF,0xC3,0xFF,0xFF,0xA2,0x60,0x3F,0xFF,0xF7,0xE7,0xE,0xFC,0xFF,0x87,0xFE,0xF,0xFF,0xC3,0xFF,0xFF,0xBE,0x6F,0xFF,0xFF,0xF3,0xE7,0x7E,0xC,0xFF,0xE1,0xFF,0xF,0xFF,0xC3,0xFF,0xFF,0xA0,0x6F,0xE0,0x0,0xFB,0xE7,0x0,0xAC,0x1,0xF1,0xFF,0xF,0xFF,0xC3,0xFF,0xFF,0x80,0x6F,0xEF,0xFE,0xFB,0xE7,0x7F,0xA0,0x1,0xF9,0x83,0x87,0xFF,0xC3,0xFF,0xFF,0x8E,0x6F,0xEF,0xE0,0x3,0xE7,0x7F,0xBD,0xF8,0xF9,0xBB,0x87,0xFF,0xC3,0xFF,0xFF,0x9E,0x60,0x0,0xF,0xFF,0xE4,0x0,0x1D,0xFC,0x79,0x83,0xC3,0xFF,0xC3,0xFF,0xFF,0x9E,0x7F,0xEF,0xFF,0xFF,0xE5,0xF7,0xD9,0xFC,0x78,0x3B,0xE1,0xFF,0xC3,0xFF,0xFF,0x9E,0x7F,0xEF,0xFF,0xFF,0xE5,0xF7,0xDB,0xFE,0x79,0x83,0xE1,0xFF,0xC3,0xFF,0xFF,0x9E,0x7F,0xEF,0xFF,0xFF,0xE5,0xF7,0xDB,0xFE,0x79,0xBB,0xE1,0xFF,0xC3,0xFF,0xFF,0x82,0x7F,0xEF,0xFF,0xFF,0xE4,0xF0,0x1B,0xFE,0x79,0x83,0xC3,0xFF,0xC3,0xFF,0xFF,0xBA,0x0,0x0,0x0,0x0,0x6,0xF7,0xFB,0xFE,0x79,0xBB,0xC3,0xFF,0xC3,0xFF,0xFF,0xBA,0x0,0x0,0x0,0x0,0x6,0xF7,0xF9,0xFE,0x79,0x83,0x87,0xFF,0xC3,0xFF,0xFF,0xBB,0xFF,0xFF,0xFF,0xEF,0xFE,0x3,0xFD,0xFE,0x79,0xDF,0xF,0xFF,0xC3,0xFF,0xFF,0xB8,0x1,0xFE,0x0,0xEF,0xC6,0xF8,0x4,0x0,0x79,0xDE,0x1F,0xFF,0xC2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xF0,0x0,0x79,0xDC,0x3F,0xFF,0xC2,0x0,0x0,0x3F,0xFC,0x0,0xFF,0x0,0x10,0xFF,0xFF,0xFE,0x78,0x1C,0x3F,0xFF,0xC2,0xFF,0xE7,0x9F,0xFF,0xFF,0xFF,0x3F,0x79,0xFF,0xFF,0xFE,0x79,0xFC,0x3F,0xFF,0xC2,0xFF,0xE7,0xCF,0xFF,0xC0,0xFF,0x3C,0x79,0xFF,0xFF,0xFE,0x79,0xFC,0x3F,0xFF,0xC2,0xFF,0xE7,0xE3,0xFF,0x9E,0xFF,0x30,0xF9,0xFF,0xFF,0xFE,0x79,0xFC,0x3F,0xFF,0xC2,0xFF,0xE1,0xF8,0x0,0x3E,0xFF,0x37,0xF9,0xFF,0xFF,0xFE,0x79,0xFC,0x3F,0xFF,0xC2,0xFF,0xE0,0xFF,0xFF,0x9E,0x0,0x0,0x0,0x0,0x7F,0xFE,0x79,0xFC,0x3F,0xFF,0xC2,0xFF,0xE4,0x3F,0xFF,0xC0,0x0,0x0,0x0,0x0,0x7F,0xFE,0x79,0xFC,0x3F,0xFF,0xC2,0xFF,0xC7,0xF,0xFF,0xFC,0xFF,0x37,0xF9,0xDE,0x7F,0xFE,0x79,0xFC,0x3F,0xFF,0xC2,0xFF,0xCF,0x83,0xFF,0xFC,0xFF,0x30,0x79,0xDE,0x7F,0xFE,0x71,0xFC,0x3F,0xFF,0xC2,0xFF,0xCF,0xE0,0x7F,0xFC,0xFF,0x3F,0x79,0xDE,0x7F,0xFC,0x1,0xFC,0x3F,0xFF,0xC2,0x7,0xCF,0xF8,0x3F,0xFC,0xFF,0x0,0x0,0x0,0x0,0x0,0x7,0xFC,0x3F,0xFF,0xC3,0xF7,0xCF,0xFF,0x1F,0xFC,0xFF,0x0,0x0,0x0,0x0,0x0,0xBF,0xFE,0x1F,0xFF,0xC3,0xF0,0x0,0x0,0x0,0x0,0x0,0x3F,0x79,0xFE,0x7F,0xFF,0xBF,0xFE,0x1F,0xFF,0xC3,0xC0,0x0,0x0,0x0,0x0,0x0,0x3F,0x79,0xFE,0x7F,0xFF,0xBF,0xFF,0xF,0xFF,0xC3,0x83,0xD7,0x9E,0xBC,0xFC,0xFF,0x3C,0x79,0x2,0x7F,0xFF,0xBF,0xFF,0xF,0xFF,0xC2,0x7,0xD7,0x9E,0xBC,0xFC,0xFF,0x38,0xF8,0x78,0x7,0xFF,0xBF,0xFF,0xF,0xFF,0x0,0x27,0xD7,0x9E,0xBC,0xFC,0xFF,0x3B,0xF9,0xFE,0x63,0xFF,0xBF,0xFF,0xF,0xFE,0x0,0xE7,0xD7,0x9E,0xBC,0xFC,0x0,0x3B,0xF9,0xFE,0x71,0xFF,0xBF,0xFF,0x87,0xFC,0x43,0xE7,0xD7,0x9E,0xBC,0x0,0x0,0x0,0x0,0x0,0x78,0xFF,0x3F,0xFF,0x87,0xF8,0xC3,0xE7,0xD7,0x9E,0xBC,0xFF,0x5F,0x0,0x0,0x0,0x7C,0x7F,0x7F,0xFF,0x87,0xF1,0xC3,0xE7,0xD7,0x9E,0xBC,0xFF,0x5F,0x9F,0x7B,0xB7,0x3E,0x3F,0x7F,0xFF,0x87,0xE3,0xC3,0xE7,0xD7,0x9E,0xBC,0xFF,0x5F,0x9F,0x7B,0xB7,0x9F,0x1F,0x7F,0xFF,0x87,0xC7,0xC3,0xE7,0xD7,0x9E,0xBC,0xFF,0x5F,0x9F,0x7B,0xB7,0x8F,0x9F,0x7F,0xFF,0x87,0xCF,0xC3,0xE7,0xD7,0x9E,0xBC,0xFF,0x5F,0x9E,0x7B,0xB7,0xC3,0xDE,0x3F,0xFF,0x87,0xCF,0xC3,0xE7,0xD7,0x9E,0xBC,0xFF,0x5F,0x9E,0xFB,0xB7,0xF3,0xDC,0x1F,0xFF,0x87,0xCF,0xC3,0xE0,0x0,0x0,0x0,0x0,0x0,0x1E,0xFB,0xB7,0xF8,0x1,0xDF,0xFF,0x87,0xCF,0xC3,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xFF,0xC0,0x0,0x7,0xC0,0x43,0xFF,0xFF,0x1F,0xFF,0xFF,0xFF,0x9F,0xFF,0xFF,0xFF,0xFF,0x0,0x0,0x7,0xCC,0x43,0xFF,0xFF,0x3F,0xFF,0xFF,0xFF,0x81,0xFF,0xFF,0xFF,0xFC,0x0,0x0,0xF,0xCC,0x43,0xFF,0xFF,0x3F,0xFF,0xFF,0xFF,0xE0,0x7F,0xFF,0xFF,0xFC,0x0,0x0,0x1F,0xCF,0xC3,0xFF,0xFE,0x7F,0xFF,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xCF,0xC3,0xFF,0xFC,0x7F,0xFF,0xFF,0xFF,0xFE,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xCF,0xC3,0xFF,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0xFF,0xFF,0xE1,0xFC,0x0,0x1,0xCF,0xC3,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0x9F,0xFF,0xFF,0xE1,0xE1,0xFF,0xDD,0xC0,0x43,0xFF,0xE1,0xFF,0xFF,0xFF,0xFE,0x1F,0x9F,0xFF,0xFF,0xE1,0xEF,0xFF,0xDD,0xCC,0x43,0xFF,0xE3,0xFF,0xFF,0xFF,0xFE,0xF,0x9F,0x3,0xFF,0xE1,0xEF,0xC0,0x1D,0xCC,0x43,0xFF,0xE7,0xFF,0xFF,0xFF,0xFE,0xCF,0x9E,0x3,0xFF,0xE1,0xEF,0x9F,0xFD,0xCF,0xC3,0xFF,0x80,0x0,0x0,0xFF,0xFE,0x8F,0x9E,0x33,0xFF,0xE1,0xE0,0x3F,0xFD,0xCF,0xC3,0xFF,0x0,0x0,0x0,0xF,0xFE,0x80,0x0,0x33,0xFF,0xC3,0xEF,0x80,0x1,0xCF,0xC3,0xFE,0x0,0x0,0x0,0x7,0xFE,0x9F,0x80,0x3,0xFF,0x83,0xEF,0xBC,0xFB,0xC7,0xC3,0xFC,0x0,0x0,0x0,0x7,0xFE,0x1F,0x9F,0x7,0xFF,0x7,0xEF,0xBC,0xFB,0xE3,0xC3,0xF8,0x3C,0xFF,0xFF,0x83,0xFF,0xFF,0x9F,0xFF,0xFE,0x7,0xE0,0x3C,0x1B,0xF1,0xC3,0xF0,0x7C,0x7F,0xFF,0x81,0xFF,0xFF,0x9F,0xFF,0xFC,0x7,0xFD,0xFC,0xB,0xF9,0xC1,0xE0,0xFE,0x3F,0xE1,0xC0,0xFF,0xFF,0x9F,0xFF,0xF8,0x21,0xFD,0xF8,0xCB,0xF9,0xE0,0xC1,0xFF,0x1F,0xED,0xE0,0x7F,0xFF,0x9F,0xFF,0xF0,0x70,0xFD,0xE0,0xC3,0xF9,0xF0,0x3,0xFF,0x83,0xED,0xE0,0x1F,0xFF,0x9F,0xFF,0xC0,0xF8,0x3D,0x87,0xCF,0xF9,0xF8,0x7,0xFF,0xC0,0xED,0xF0,0x3,0xFF,0x9F,0xFE,0x1,0xCE,0xD,0xF,0xCF,0xF9,0xFC,0xF,0xFF,0xF8,0x0,0x18,0x0,0x7F,0x9F,0xFC,0x3,0xC7,0x84,0x3F,0x8F,0xF9,0xFE,0x1F,0x80,0xFE,0x6F,0xDF,0x0,0x0,0x0,0x0,0x7,0xD7,0xE0,0xBF,0x1F,0xF9,0xFF,0xFF,0x3E,0xFE,0x6F,0xDF,0xE0,0x0,0x0,0x0,0x3F,0x87,0xE3,0xBE,0x3F,0xF9,0xFF,0xFC,0x7E,0xFE,0x60,0x0,0xFC,0x0,0x0,0x1,0xFE,0x37,0xE7,0xBC,0x7F,0xF9,0xFF,0xF9,0xFE,0xFE,0x7F,0xFE,0xFE,0x0,0x0,0x3,0xF8,0x73,0xE7,0x3C,0xFF,0xF9,0xFC,0x3,0xC0,0x0,0x0,0x2,0xFF,0xFF,0x9F,0xFF,0xE1,0xFB,0xE7,0x7C,0xFF,0xF9,0xFD,0xFF,0x80,0x0,0x0,0x7A,0xFF,0xFF,0x9F,0xF8,0x7,0xFB,0xE7,0x7C,0xFF,0xF8,0x7D,0xFF,0x9E,0xFF,0xFF,0x78,0x1,0xFF,0x9F,0xFB,0xFF,0xFB,0xE7,0x7C,0xFF,0xF3,0x1D,0xFF,0x9E,0xFF,0xFF,0x3,0xFD,0xFF,0x9F,0xF1,0xFF,0xF1,0xC6,0x78,0x7F,0xF7,0xC0,0x7F,0x9E,0xFF,0xFF,0xDF,0xFC,0x0,0x0,0x4,0x0,0x4,0x6,0xFB,0x7F,0xE7,0xFF,0x0,0x1E,0xFF,0xF0,0x0,0x3C,0x68,0x0,0x0,0x4,0x0,0xE,0xFB,0x7F,0xEF,0xFF,0x0,0x1E,0x7F,0x0,0xFF,0x80,0x0,0x2F,0xBF,0xF1,0xFB,0xBE,0xFB,0x7F,0xEF,0xFE,0x7B,0xFF,0x7F,0x7E,0x3F,0xFC,0x3F,0x2F,0x9F,0xFB,0xFB,0xBE,0xFB,0x7F,0xE7,0xFE,0xF9,0xFF,0x0,0x7F,0x9F,0xFC,0x0,0x2F,0xDF,0xFB,0xFB,0xBE,0x3,0x7F,0xF0,0x7C,0xFC,0xFF,0xFB,0xFF,0xC7,0xFF,0xFF,0xE0,0xD0,0x3,0xFB,0xBE,0xFF,0x7F,0xFF,0x1,0xFE,0x0,0x3,0xFF,0xF1,0xFF,0xFF,0xEE,0x7,0xF8,0x0,0x0,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x0,0x0,0xF,0xFF,0xFF,0xFF,0xFE,0x0,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,};


byte getTile(byte x, byte y){
  //Serial.print(y);  Serial.print(" <= y | x => "); Serial.print(x);Serial.print(" || ");
  //le decalage dépend de la position du joueur je divise x/8 car j'ai 8 bit dans un byte. puis je décale du nombre de bit util pour ne garder que le premier
  return (pgm_read_byte(world + (y*16) + x/8) >> (7-((x%8)))& B00000001);
}

void drawWorld(){
   for(byte y = max(0, (camera_y)/16); y < min(WORLD_W, (camera_y+LCDHEIGHT)/16+1); y++){
    for(byte x = max(0, (camera_x)/16); x < min(WORLD_H, (camera_x+LCDWIDTH)/16+1); x++){
      byte spriteID = getTile(x,y);
      if(spriteID == 0)
        continue;
        
        byte numSprite = 2;
       //Verrification des zone de sprite
        for(byte i=0;i<NB_ZONE;i++)
        {
          byte decalage = 5*i;
          byte x1 = pgm_read_byte(Zones + decalage);
          byte y1 = pgm_read_byte(Zones +decalage+1);
          byte x2 = pgm_read_byte(Zones+decalage+2);
          byte y2 = pgm_read_byte(Zones+decalage+3);
          
          if(gb.collidePointRect(x,y,x1,y1,x2-x1,y2-y1))
          {
            numSprite = pgm_read_byte(Zones+decalage+4);
            break;
          }
        }
      //coordinates on the screen depending on the camera position
      int x_screen = x*16 - camera_x;
      int y_screen = y*16 - camera_y;
      gb.display.drawBitmap(x_screen, y_screen, GetSpriteById(numSprite));
    }
  }
  
 
  //Test map 
 /* for(byte y=0;y<128;y++)
    {
        for(byte x=0;x<128;x++)
        {
            Serial.print(getTile(x,y));
        }
          Serial.println("");
    }
  drawTitleScreen();*/
}

void drawMap(){
  /*gb.display.fillRect(0,0,18,18);
  gb.display.setColor(WHITE);
  for(byte y = 0; y < 64; y++){
    for(byte x = 0; x < 64; x++){
      char tile_x = x + player.x/64 - 8;
      char tile_y = y + player.y/64 - 8;
      if(tile_x < 0 || tile_x > WORLD_W || tile_y < 0 || tile_y > WORLD_H)
        continue;
      if(getTile(x + player.x, y + player.y) == 0)
        gb.display.drawPixel(x+1, y+1);
    }
  }
  gb.display.setColor(BLACK);
  gb.display.drawPixel(9,9);*/
}



