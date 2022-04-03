void kernel_entry() {
    char* video_memory = (char*) 0xb8000;       // video memory begins at address 0xb8000
    *video_memory = 'X';                        // write a 'X' to the first position of video memory
}
