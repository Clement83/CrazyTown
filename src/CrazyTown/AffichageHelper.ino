void drawBitmapAngle(int8_t x, int8_t y, const uint8_t *bitmap,float angle) {
	int8_t w = pgm_read_byte(bitmap);
	int8_t h = pgm_read_byte(bitmap + 1);
        int8_t centerX = w/2;
        int8_t centerY = h/2;
	bitmap = bitmap + 2; //add an offset to the pointer to start after the width and height
    int8_t i, j, byteWidth = (w + 7) / 8;
    float sinA = sin(angle);
    float cosA = cos(angle);
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            if (pgm_read_byte(bitmap + j * byteWidth + i / 8) & (B10000000 >> (i % 8))) {
              
              int8_t desX =   (i - centerX) * cosA - (j-centerY) * sinA;
              int8_t desY = (i-centerX) * sinA + (j-centerY) * cosA;
              gb.display.drawPixel(x + desX, y + desY);
            }
        }
    }
}
