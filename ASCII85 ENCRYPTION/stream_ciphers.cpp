/*
 * Encode_decode.cpp
 *
 *  Created on: Nov. 6, 2019
 *      Author: Simon
 */
#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING
int main();
#endif
char *encode(char *plaintext, unsigned long key);
char *decode( char *ciphertext, unsigned long key);

#ifndef MARMOSET_TESTING
int main() {

	unsigned long key{51323};

	char str0[]{ "Hello world! My Name is Simon" };
	std::cout << "\"" << str0 << "\"" << std::endl;

	char *ciphertext{ encode( str0, key)};
	std::cout << "\"" << ciphertext << "\"" << std::endl;

	char *plaintext{ decode(ciphertext, key)};
	std::cout << "\"" << plaintext << "\"" << std::endl;

	delete[] plaintext;
	plaintext = nullptr;
	delete[] ciphertext;
	ciphertext = nullptr;


	return 0;
}
#endif


char *decode( char *ciphertext, unsigned long key){
	unsigned char count_char {'a'};
	unsigned int counter_ciphertext { 0 };
	unsigned int num_ciphertext {0};
	unsigned int decimal_num {0};
	unsigned char state_array[256] { };
	unsigned int j { 0 };
	unsigned int i { 0 };
	unsigned int k { 0 };
	unsigned int swapper { 0 };
	unsigned int r { 0 };
	unsigned int R { 0 };

	while (count_char != '\0'){
				count_char = *(ciphertext +counter_ciphertext);
				++counter_ciphertext;
			}
			--counter_ciphertext;


			while (counter_ciphertext !=0){
				++num_ciphertext;
				counter_ciphertext = counter_ciphertext - 5;
			}


			char *decode_array {new char[(num_ciphertext*4)+1]{}};


			for(unsigned int n{0}; n < (num_ciphertext); ++n){

				decimal_num = (*(ciphertext + n*5+4)- '!')*pow(85, 0);
				decimal_num += (*(ciphertext + n*5+3)- '!')*pow(85, 1);
				decimal_num += (*(ciphertext + n*5+2)- '!')*pow(85, 2);
				decimal_num += (*(ciphertext + n*5+1)- '!')*pow(85, 3);
				decimal_num += (*(ciphertext + n*5)-'!')*pow(85, 4);

				*(decode_array + n*4) = ((decimal_num >> 24) & 0xff);
				*(decode_array + n*4+1) = ((decimal_num >> 16) & 0xff);
				*(decode_array + n*4+2) = ((decimal_num >> 8) & 0xff);
				*(decode_array + n*4+3) = ((decimal_num) & 0xff);

			}

			// Initializing State array to 0-255
				for (unsigned int a { 0 }; a < 256; ++a)
						{

					state_array[a] = a;
				}
				// Scrambles state array
				for (unsigned int b { 0 }; b < 256; ++b) {
					k = (i % 64);
					j = (j + ((key & (1L << k)) >> k) + state_array[i]) % 256;
					swapper = state_array[i];
					state_array[i] = state_array[j];
					state_array[j] = swapper;
					++i;
					i %= 256;
				}

				char *a_plaintext{new char[num_ciphertext*4 +1]{}};

				for (unsigned int g { 0 }; g < num_ciphertext*4+1; ++g) {
					i++;
					i %= 256;

					j = (j + state_array[i]) % 256;
					swapper = state_array[i];
					state_array[i] = state_array[j];
					state_array[j] = swapper;

					r = (state_array[i] + state_array[j]) % 256;
					R = state_array[r];

					*(a_plaintext+g) = (*(decode_array + g) ^ R);

				}

				*(a_plaintext + num_ciphertext*4) = '\0';

				delete[] decode_array;
				decode_array = nullptr;

				return a_plaintext;
}

char *encode(char *plaintext, unsigned long key){
	unsigned char state_array[256] { };
	unsigned int j { 0 };
	unsigned int i { 0 };
	unsigned int k { 0 };
	unsigned int swapper { 0 };
	unsigned int r { 0 };
	unsigned int R { 0 };
	unsigned int counter_plaintext { 0 };
	unsigned char count_char {'a'};
	unsigned int static_count { 0 };
	unsigned num_armour{};
	unsigned int base_num{0};


	// Initializing State array to 0-255
	for (unsigned int a { 0 }; a < 256; ++a)
			{

		state_array[a] = a;
	}
	// Scrambles state array

	for (unsigned int b { 0 }; b < 256; ++b) {
		k = (i % 64);
		j = (j + ((key & (1L << k)) >> k) + state_array[i]) % 256;
		swapper = state_array[i];
		state_array[i] = state_array[j];
		state_array[j] = swapper;
		++i;
		i %= 256;
	}

	//Counts characters in array before null character
		while (count_char != '\0') {
			count_char = plaintext[counter_plaintext];
			++counter_plaintext;
		}
		--counter_plaintext;


	//Static_count holds value of original number of characters w/o the null
	//Counter_plaintext will be incremented to the number of characters required for it to be a multiple of 4

		static_count = counter_plaintext;

		while (counter_plaintext % 4 != 0) {
			++counter_plaintext;
		}

		 char *ciphercopy{new char[counter_plaintext]{}};

		//Copies original characters to new array

		for (unsigned int d { 0 }; d < static_count; d++)
		{
			ciphercopy[d] = plaintext[d];
		}

		// Adds proper number of null characters
		for (unsigned int e { 0 }; e < (counter_plaintext - static_count); ++e) {
			ciphercopy[static_count + e] = '\0';
		}


	for (unsigned int g { 0 }; g < counter_plaintext; ++g) {
		i++;
		i %= 256;

		j = (j + state_array[i]) % 256;
		swapper = state_array[i];
		state_array[i] = state_array[j];
		state_array[j] = swapper;

		r = (state_array[i] + state_array[j]) % 256;
		R = state_array[r];

		ciphercopy[g] = (ciphercopy[g] ^ R);
	}
	// Test for ciphercopy output
	// Start ASCII Armour


	// Only works if counter_plaintext is an exact multiple of four because it is an unsigned integer

	num_armour = counter_plaintext/4;

	char *armour_array{new char[5*num_armour + 1]{}};


	for(unsigned int d{0}; d < num_armour; ++d)
	{
		base_num = (static_cast<unsigned char>(ciphercopy[4*d]) << 24);
		base_num += (static_cast<unsigned char>(ciphercopy[4*d+1]) << 16);
		base_num += (static_cast<unsigned char>(ciphercopy[4*d+2]) << 8);
		base_num += (static_cast<unsigned char>(ciphercopy[4*d+3]));


		armour_array[d*5 +4] = (base_num % 85 +'!');
		base_num = (base_num/85);

		armour_array[d*5 +3] = (base_num % 85 +'!');
		base_num = (base_num/85);


		armour_array[d*5 +2] = (base_num % 85 +'!');
		base_num = (base_num/85);

		armour_array[d*5 +1] = (base_num % 85 +'!');
		base_num = (base_num/85);

		armour_array[d*5] = (base_num % 85 +'!');
		base_num = (base_num/85);


	}
 // Should it be plus one or not when adding the null character??s
	armour_array[5*num_armour] = '\0';


	delete[] ciphercopy;
	ciphercopy = nullptr;


	return armour_array;

	//To get number to convert to base 85 add four bytes of data and have bit shift first element 24 then 16 then 8 then 0
	// print out backwards numbers stored in reverse order
	//use static cast to unsigned char to print the char to the console
	// static_cast <unsigned char> (array_name[k]
}




