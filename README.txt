Name: Jayson Tan 
Course: CSCI 335
Instructor: Ioannis Stamos 
Term: Spring 2019 
Assignment: Assignment 3 - Homework 3 - Hash Table Efficiency and Spell Check Implementation

Compiled on: gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
NOTE TO PROFESSOR STAMOS: As discussed in the email with Daniel Mallia, outputs from different computers (please see above for compiler information)

*************************ADDITIONAL FILES***************************

i. linear_probing.h and double_probing.h were added

ii. A testFile.cpp is included for testing individual/problematic functions. 
	Note this should not be taken into account when grading and does not affect the program in anyway.

**************************LEARNING OUTCOMES*************************
i. Part(1) and Part(2) were completed successfully with the outputs matching the expected outcome


	Part 1 and 2: 

	// QUADRATIC
	Words filename: words.txt
	Query filename: query_words.txt
	Collisions: 21068
	Number of items: 25143
	Size of hash table: 55609
	Load factor: 0.452139
	Avg. number of collisions: 0.837927
	alone: Found | Number of Probes: 1
	binary: Found | Number of Probes: 1
	catastrophe: Found | Number of Probes: 1
	dog: Found | Number of Probes: 1
	family: Found | Number of Probes: 1
	loath: Found | Number of Probes: 1
	oath: Found | Number of Probes: 2
	zebra: Found | Number of Probes: 1
	bikini: Found | Number of Probes: 1
	zucchiniaa: Not Found | Number of Probes: 1
	lwa: Not Found | Number of Probes: 9
	panacea: Found | Number of Probes: 1
	pnca: Not Found | Number of Probes: 1

	// LINEAR
	Words filename: words.txt
	Query filename: query_words.txt
	Collisions: 23965
	Number of items: 25143
	Size of hash table: 55609
	Load factor: 0.452139
	Avg. number of collisions: 0.953148
	alone: Found | Number of Probes: 1
	binary: Found | Number of Probes: 1
	catastrophe: Found | Number of Probes: 1
	dog: Found | Number of Probes: 1
	family: Found | Number of Probes: 1
	loath: Found | Number of Probes: 1
	oath: Found | Number of Probes: 2
	zebra: Found | Number of Probes: 2
	bikini: Found | Number of Probes: 1
	zucchiniaa: Not Found | Number of Probes: 1
	lwa: Not Found | Number of Probes: 6
	panacea: Found | Number of Probes: 1
	pnca: Not Found | Number of Probes: 1

	// DOUBLE
	Words filename: words.txt
	Query filename: query_words.txt
	Collisions: 18859
	Number of items: 25143
	Size of hash table: 55609
	Load factor: 0.452139
	Avg. number of collisions: 0.75007
	alone: Found | Number of Probes: 1
	binary: Found | Number of Probes: 1
	catastrophe: Found | Number of Probes: 1
	dog: Found | Number of Probes: 1
	family: Found | Number of Probes: 1
	loath: Found | Number of Probes: 1
	oath: Found | Number of Probes: 2
	zebra: Found | Number of Probes: 1
	bikini: Found | Number of Probes: 1
	zucchiniaa: Not Found | Number of Probes: 1
	lwa: Not Found | Number of Probes: 5
	panacea: Found | Number of Probes: 1
	pnca: Not Found | Number of Probes: 1

ii. Part 3 - Spell checker was implemented using quadratic probing

	Part 3: 

	Output for: document1_short.txt

	Input document filename is document1_short.txt
	Input dictionary filename is wordsEn.txt
	TestFunctionForHashTable...
	Words filename: wordsEn.txt
	Query filename: document1_short.txt

	// ADD A CHARACTER IN EACH INDEX
	Misspelled word: comlete | Corrected word: complete
	Misspelled word: patels | Corrected word: pastels
	Misspelled word: patels | Corrected word: pastels

	// REMOVE A CHARACTER IN EACH INDEX
	Misspelled word: patels | Corrected word: pates
	Misspelled word: deciasion | Corrected word: decision
	Misspelled word: patels | Corrected word: pates
	Misspelled word: lwa | Corrected word: wa
	Misspelled word: lwa | Corrected word: la

	// SWAP CHARACTERS IN EACH INDEX
	Misspelled word: lwa | Corrected word: law


	Output for: document1.txt

	Input document filename is document1.txt
	Input dictionary filename is wordsEn.txt
	TestFunctionForHashTable...
	Words filename: wordsEn.txt
	Query filename: document1.txt

	// ADD A CHARACTER IN EACH INDEX
	Misspelled word: patels | Corrected word: pastels
	Misspelled word: patel | Corrected word: pastel
	Misspelled word: pt | Corrected word: apt
	Misspelled word: pt | Corrected word: opt
	Misspelled word: pt | Corrected word: pat
	Misspelled word: pt | Corrected word: pct
	Misspelled word: pt | Corrected word: pet
	Misspelled word: pt | Corrected word: pit
	Misspelled word: pt | Corrected word: pot
	Misspelled word: pt | Corrected word: put
	Misspelled word: pt | Corrected word: pts
	Misspelled word: complte | Corrected word: complete
	Misspelled word: patels | Corrected word: pastels
	Misspelled word: patels | Corrected word: pastels
	Misspelled word: wih | Corrected word: wish
	Misspelled word: wih | Corrected word: with
	Misspelled word: reliminary | Corrected word: preliminary
	Misspelled word: ealier | Corrected word: mealier
	Misspelled word: ealier | Corrected word: vealier
	Misspelled word: ealier | Corrected word: earlier
	Misspelled word: im | Corrected word: aim
	Misspelled word: im | Corrected word: dim
	Misspelled word: im | Corrected word: him
	Misspelled word: im | Corrected word: jim
	Misspelled word: im | Corrected word: lim
	Misspelled word: im | Corrected word: nim
	Misspelled word: im | Corrected word: rim
	Misspelled word: im | Corrected word: tim
	Misspelled word: im | Corrected word: vim
	Misspelled word: im | Corrected word: ibm
	Misspelled word: im | Corrected word: ism
	Misspelled word: im | Corrected word: imp
	Misspelled word: dont | Corrected word: donut
	Misspelled word: thrugh | Corrected word: through
	Misspelled word: diret | Corrected word: direct
	Misspelled word: diret | Corrected word: direst
	Misspelled word: sony | Corrected word: stony
	Misspelled word: sony | Corrected word: sonny
	Misspelled word: sony | Corrected word: sonny
	Misspelled word: sony | Corrected word: stony
	Misspelled word: sony | Corrected word: sonny
	Misspelled word: sony | Corrected word: sonny
	Misspelled word: sony | Corrected word: stony
	Misspelled word: sony | Corrected word: sonny
	Misspelled word: sony | Corrected word: sonny
	Misspelled word: sony | Corrected word: stony
	Misspelled word: sony | Corrected word: sonny
	Misspelled word: sony | Corrected word: sonny
	Misspelled word: weve | Corrected word: weave
	Misspelled word: dont | Corrected word: donut
	Misspelled word: dont | Corrected word: donut
	Misspelled word: dont | Corrected word: donut

	// REMOVE A CHARACTER IN EACH INDEX
	Misspelled word: patels | Corrected word: pates
	Misspelled word: patel | Corrected word: pate
	Misspelled word: 9th | Corrected word: th
	Misspelled word: complte | Corrected word: compte
	Misspelled word: patels | Corrected word: pates
	Misspelled word: patels | Corrected word: pates
	Misspelled word: papre | Corrected word: pare
	Misspelled word: dont | Corrected word: dot
	Misspelled word: dont | Corrected word: don
	Misspelled word: diret | Corrected word: diet
	Misspelled word: diret | Corrected word: dirt
	Misspelled word: diret | Corrected word: dire
	Misspelled word: sony | Corrected word: soy
	Misspelled word: sony | Corrected word: son
	Misspelled word: sony | Corrected word: soy
	Misspelled word: sony | Corrected word: son
	Misspelled word: sony | Corrected word: soy
	Misspelled word: sony | Corrected word: son
	Misspelled word: sony | Corrected word: soy
	Misspelled word: sony | Corrected word: son
	Misspelled word: theyre | Corrected word: there
	Misspelled word: theyre | Corrected word: there
	Misspelled word: weve | Corrected word: eve
	Misspelled word: weve | Corrected word: wee
	Misspelled word: dont | Corrected word: dot
	Misspelled word: dont | Corrected word: don
	Misspelled word: dont | Corrected word: dot
	Misspelled word: dont | Corrected word: don
	Misspelled word: doesnt | Corrected word: doest
	Misspelled word: dont | Corrected word: dot
	Misspelled word: dont | Corrected word: don
	Misspelled word: doesnt | Corrected word: doest

	// SWAP CHARACTERS IN EACH INDEX
	Misspelled word: papre | Corrected word: paper
	Misspelled word: indiivdual | Corrected word: individual


iii. Some errors/bugs that I encountered along the way were: 
	1) Expected output of collisions and probing are different on Macs vs gcc 
	2) As per discussion in classroom, we are allowed to ignore 'I' since there are too many instances of it in document1.txt
	3) As per discussion in classroom, we are allowed to display duplicate outputs 

**************************COMPILE INSTRUCTIONS*************************

You can compile everything by typing 

make clean
make all

Your programs should run from the terminal as follows:
./create_and_test_hash <words file name> <query words file name> <flag>
<flag> should be “quadratic” for quadratic probing, “linear” for linear probing, and “double” for double hashing.

For example you can write on the terminal:
./create_and_test_hash words.txt query_words.txt quadratic

You can compile Part 3 - Spell checker by: 
spell_check <document file> <dictionary file>
A small document named document1_short.txt (and document1.txt) and a dictionary file with approximately 100k words named wordsEn.txt are provided

For example you can write on the terminal:
./spell_check document1.txt wordsEn.txt

By typing 

make clean

You delete all .o files and executables.


