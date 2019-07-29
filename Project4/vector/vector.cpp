
#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>


namespace structures {

	Vector::Vector(size_t size) :                                                                             // robi sa to cez inicializacny zoznam lebo to je rychlejsie																				   
		memory_(calloc(size, 1)), // lebo su to byte v tomto pripade tak preto 1 a inicializujem atribut        // uz pri konstruovani objektu sa nastavaju atributy
		size_(size) // atributu size_ pridelim parameter size
	{

	}

	Vector::Vector(const Vector& other) : // tu si vytvorim asi novy vektor other cez kopirovaci konstruktor
		Vector(other.size_)
	{
		//smernik na atribut memory      // priamo objekt
		memcpy(this->memory_, other.memory_, size_);  // this je smernik na objekt a other je priamo objekt

	}

	Vector::~Vector()
	{
		free(this->memory_);   // uvolnenie pamati cez smernik
		memory_ = nullptr; // smernik uz neukazuje na nic platne tak ho dam na nulu
		size_ = 0;
	}

	Structure* Vector::clone() const // kopia objektu
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure & Vector::operator=(const Structure & other) // operator priradenia
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		if (this != &other) // ak adresa objektu v ktorom som je rozna od adresy objektu ineho tak to urob

		{
			this->size_ = other.size_;
			memory_ = realloc(this->memory_, size_); //zmena velkosti
			memcpy(this->memory_, other.memory_, size_);
		}
		return *this; // objekt na vektor by mal vratit 
					  // *this znamena adresa vektora a chcem priamo ten vektor tak dereferencia
	}

	bool Vector::operator==(const Vector& other) const
	{
		return size_ == other.size_&& memcmp(memory_, other.memory_, size_) == 0;
	}

	byte& Vector::operator[](const int index) // ked tam je ampersant tak si ho odmyslim
	{
		// ked tam je & vrat ten original presne tu bumku

		DSRoutines::rangeCheckExcept(index, size_, "Invalid index"); // tu kontrolujem index ze ci ma dobru hodnotu, ds routines kontroluje index a max. size 
																	 //ak je v poriadku tak ok ak nie tak ptm vyhodi vynimku
		return*(reinterpret_cast<byte*>(memory_) + index); // pretypovanie na byte lebo chcem skakat po jednom 
														   // reinterper cast sluzi na pretypovanie smernikov (co idem pretypovat) <na co idem pretypovat>
	}

	byte Vector::operator[](const int index) const  // toto je rovnake ako predtym 
	{ // ked tam nie je tak vytvori kopiu a tu kopiu vrati
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index");

		return*(reinterpret_cast<byte*>(memory_) + index);
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		if (count != 0) {
			DSRoutines::rangeCheckExcept(index, size_, "Error.");
			DSRoutines::rangeCheckExcept(index + count - 1, size_, "Error.");
			DSRoutines::rangeCheckExcept(count - 1, size_, "Error.");
			byte * start = reinterpret_cast<byte *>(memory_) + index;
			byte * end = start + count - 1;
			if ((&dest >= start && &dest <= end) || (&dest + count - 1 >= start && &dest + count - 1 <= end)) {
				memmove(&dest, start, count);
			}
			else {
				memcpy(&dest, start, count);
			}

		}
		return dest;
	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		if (length != 0) {
			DSRoutines::rangeCheckExcept(srcStartIndex, src.size_, "Invalid Source start index.");
			DSRoutines::rangeCheckExcept(srcStartIndex + length - 1, src.size_, "Invalid Source start index.");
			DSRoutines::rangeCheckExcept(destStartIndex, dest.size_, "Invalid Dest start index.");
			DSRoutines::rangeCheckExcept(destStartIndex + length - 1, dest.size_, "Invalid Dest start index.");
			DSRoutines::rangeCheckExcept(length - 1, src.size_, "Invalid length.");

			byte * src_start = reinterpret_cast<byte *>(src.memory_) + srcStartIndex;
			byte * src_end = src_start + length - 1;
			byte * dest_start = reinterpret_cast<byte *>(dest.memory_) + destStartIndex;
			byte * dest_end = dest_start + length - 1;

			if ((src_start >= dest_start && src_start <= dest_end) || (src_end >= dest_start && src_end <= dest_end)) {
				memmove(dest_start, src_start, length);
			}
			else {
				memcpy(dest_start, src_start, length);
			}
		}
	}

	byte* Vector::getBytePointer(const int index) const // vracia adresu prvku ktory sa nachadza na prislusnom indexe
	{

		DSRoutines::rangeCheckExcept(index, size_, "Invalid index");

		return(reinterpret_cast<byte*>(memory_) + index);

	}

}