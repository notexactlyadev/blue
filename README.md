# 'Blue'

![](http://www1.frm.utn.edu.ar/itren/logo-blue.gif "Logo")

Written based on the sources/documentation provided by the following [Universidad Tecnologica Nacional -- Facultad Regional Mendoza](frm.utn.edu.ar) alumni:
____

Alberto Ferrari -- original version for the IBM PC computer, written in C89 for the MS-DOS platform.

José M. Muñiz -- current version written in Delphi 7
____
### Synopsis ([Translated from the original](http://www1.frm.utn.edu.ar/tecnicad2/tec_dig2/tools/te2blue.html))
____

>*'Blue' is a basic educational computer created by Caxton Foster in "Computer Architecture". It is named after after the case that held the machine, which was of color blue.*
*BLUE is a digital automatic computer, that uses binary in two's complement, that stores programs and uses fixed-size long words. It has a central memory of up to 4096 cells. Each cell contains 16 bits, and memory access time is of a microsecond. Whenever it is used to store data, this cells are treated as words of 15 bits, plus a single signing bit.*

>*Whenever they are used to store instructions, they are divided in two, 4 bits are used to store the operation code(s), and the other 12 bits are used as the address field. There is an accumulator of 16 bits, a Instruction Register of 16 bits, and a Program Counter of 12 bits.*

>*The original Blue emulator was used in the Digital Techniques II course as a teaching tool until 1997. In 1998 with a new course program, Simplez was adopted as the course educational computer*
____

The source code of the original version is available in [here](http://www1.frm.utn.edu.ar/tecnicad2/tec_dig2/tools/te2blue.html), is provided as an historical archive. This code is currently **not** compilable as it uses MS-DOS specific features, as it was intended to only ever run in the IBM PC platform, and it is written in ANSI C (also known as C89), and was last edited in 1991.
____
Now, a simulator rewritten in Borland Delphi is the one currently being used in the "Computer Architecture" course.

### So, what is the point of all this?

It is simply a personal proyect, because I wanted to do it as a challenge, this is simply a interpreter based on the lectures given and theory described in the "Computer Architecture" course, in the C++ programming language, to teach myself some fundamentals of writting virtual machines and stuff.

