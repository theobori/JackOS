[33mcommit 3ac93e39bbb13c7c9b92ecacd0158f2af6d3e865[m[33m ([m[1;36mHEAD -> [m[1;32mhugo-marrasse_WIP_keyboard-inputs[m[33m, [m[1;31morigin/hugo-marrasse_WIP_keyboard-inputs[m[33m)[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Fri Apr 8 19:42:21 2022 +0200

    [WIP]
    
    Work in progress keyboard management

[33mcommit f89718731ad3678597fc98084437c790cb9ee8d3[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Thu Apr 7 23:07:53 2022 +0200

    [Add] Add of interrupts management
    
    Interrupts management is here to handle bios calls like keyboard and mouse clicks
    
    Generals:
        - Makefile modifications to handle the new interrupt management
        - src/kernel/entry_point/entry(.c & .h) modifications to initialize the idt and to test interrupts
    
    Boot (src/boot/):
        - Modifications of sector to read (2 -> 31 (31 coz it's big)) because 1 sector = 512 bytes and it was too small to contains the kernel.
        - src/kernel/drivers/interrupts/ folder that will handle all the generals interrupts handle files.
    
    Utils: (src/utils/):
        - create utils file for string management(strlen, revstr & itoa functions)

[33mcommit 61c6dec233334644933beffec0dd436454da477c[m
Merge: 9f42a48 8e648f6
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Thu Apr 7 19:16:46 2022 +0200

    Merge branch 'master' into hugo-marrasse_WIP_keyboard-inputs

[33mcommit 9f42a4886f915ff72cec2fa936ba344362fbeb0e[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Tue Apr 5 00:41:58 2022 +0200

    [ADD] Add of first driver folder, for keyboard inputs
    
    Initializing drivers folder with keyboard files, it will be used to keyboard management
    
    src/kernel/drivers :
        - keyboard.c will contains the keyboard management functions
        - keyboard.h for now, contains only keyboard bios keys (it's key code returned by bios)

[33mcommit 8e648f63c5c2ae7c270cc67fc131f934ae4b83bc[m[33m ([m[1;31morigin/master[m[33m, [m[1;31morigin/hugo-marrasse_WIP_screen-driver[m[33m, [m[1;31morigin/hugo-marrasse_WIP_dev[m[33m, [m[1;32mmaster[m[33m, [m[1;32mhugo-marrasse_WIP_dev[m[33m)[m
Merge: 49f7af6 e5baf91
Author: pulk66-s <70581752+pulk66-s@users.noreply.github.com>
Date:   Mon Apr 4 15:34:20 2022 +0200

    Merge pull request #4 from theobori/theobori_WIP_dev
    
    Changing author link in README.md

[33mcommit e5baf91adcc7289a18a8a34b388568d9ae71eba7[m
Author: theobori <theo1.bori@epitech.eu>
Date:   Mon Apr 4 09:01:31 2022 +0200

    README:
        - Edited authors github link

[33mcommit 49f7af6ef7fc8f86a1f6c42d0e1d92ddbf5e6c2c[m
Merge: abea2e5 3ba8caf
Author: _____ <71843723+theobori@users.noreply.github.com>
Date:   Mon Apr 4 02:00:11 2022 +0200

    Merge pull request #3 from theobori/hugo-marrasse_WIP_dev
    
    [ADD] Adding some libs functions for VGA print

[33mcommit 3ba8caf5255760ed9cebba0bf55468a605659c59[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Mon Apr 4 01:53:05 2022 +0200

    [ADD] Adding some libs functions for VGA print
    
    Adding kprint, kprint_int & screen_clear functions.
    Adding Colors enum and SET_COLOR macro.
    
    kernel:
        - src/kernel/utils/ : all the files are global utils functions, not sure for the folder name but it's a good idea to keep it.
        - Adding of header files with guards.
        - Other minor changes.
    
    src/kernel/utils/ :
        - Adding of kprint function that print a string on the screen.
        - Adding of kprint_int function that print an integer on the screen.
        - Adding of screen_clear function that clear the screen

[33mcommit abea2e50df408e91f684d4e875fe5e45610648f0[m
Merge: 612f83d 0c3859c
Author: _____ <71843723+theobori@users.noreply.github.com>
Date:   Mon Apr 4 01:02:30 2022 +0200

    Merge pull request #2 from theobori/hugo-marrasse_WIP_dev
    
    Hugo marrasse wip dev

[33mcommit 612f83d89081e84967258aabe6f2240f77405897[m
Merge: 2552bcf adf8b2a
Author: pulk66-s <70581752+pulk66-s@users.noreply.github.com>
Date:   Mon Apr 4 01:00:28 2022 +0200

    Merge pull request #1 from theobori/theobori_WIP_dev
    
    [Add] Adding README and some files that give informations about the p…

[33mcommit 0c3859ca51c688b51af435781476e2f3040c4a28[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Mon Apr 4 00:53:00 2022 +0200

    [FIX] Fixing Makefile issues
    
    Changing Makefile rules because it was not working properly.
    Changing kernel entry point file name.

[33mcommit 691dbb94f2896fa4bf45dbb62c227287448e32b0[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Mon Apr 4 00:49:26 2022 +0200

    [Add] Adding of kernel initialization in C
    
    Adding first kernel code in C, initializing by asm kernel entry point
    Adding of switching mode from real mode to protected mode in asm
    
    Generals:
        - Makefile changes, adding of rules for C compile and splitting into many rules for kernel kernel_entry & boot_sector
    
    Doc:
        - Modifications into doc/my_notes.txt (this file is some garbages and must be replaced by true doc ASAP)
    
    src/boot/ :
        - Adding of hard drive reader into src/boot/disk.asm
        - Adding of gdt initialization into src/boot/gdt.asm
        - Adding of kernel entry point in src/boot/kernel_entry.asm
        - Adding of mode switching (real mode -> protected mode) into src/boot/switch_pm.asm
        - Other minors changes
    
    kernel :
        - Adding of an entry point into src/kernel_entry/entry_point/main.c, this is just entry point for C kernel, for now it's only displaying 'X' in the top left corner in VGA

[33mcommit adf8b2aa02e654fb7ecb0c7c761cbbe2132e1a2c[m
Author: theobori <theo1.bori@epitech.eu>
Date:   Mon Apr 4 00:42:30 2022 +0200

    [Add] Adding README and some files that give informations about the project
    
    Documentation:
        - Created a README file that explain the project and explains how to use it
        - Added some markdown files in doc/ that inform the steps we have taken and those to come, the build and how to contribute

[33mcommit 2bc2124161156c64f0cfdde50d50230175edec1e[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Sun Apr 3 22:07:47 2022 +0200

    [ADD] Initializing of the new branch
    
    Creating of the branch with first 16-bits JackOS.
    Starting build structure and file architecture.
    
    General:
            - Adding of Makefile for automate compiling files (all for compiling only & run for compiling and launching).
            - add of src/boot that must contains all the files for boot_sector and kernel launch.
            - add of src/boot/utils that must store all the """global functions""" like print, read_disk or anything that can be used in other programs.
            - updating of my_notes.txt (it's garbage and temporary file that just store notes beacause we are just newbies)
    
    Boot sector:
            - initializing JackOS with basic 16 bits architecture, it will only print a welcome message ("Welcome into JackOS !")

[33mcommit 2c33490237c83249ce8bbc602b97d8c4ce48952b[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Fri Apr 1 04:05:54 2022 +0200

    [ADD] Adding notes
    
    Doc :
            - Notes are for global notation when learning
    
    General:
            - Add doc/notes.txt

[33mcommit 2552bcf2bceebd0638eb5bd6ea1245b4dee2f2f7[m
Author: pulk66-s <hugo.marrasse@epitech.eu>
Date:   Thu Mar 31 22:38:13 2022 +0200

    [ADD] initialization of Drunkos project
    
    Goal : build first os for getting knowledges. This is done with tutorial help
    tutorial link : https://github.com/cfenollosa/os-tutorial.git
    
    General:
            - Creation of doc/
            - Add LICENSE
