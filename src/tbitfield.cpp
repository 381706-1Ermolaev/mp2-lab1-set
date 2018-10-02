// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len < 0) throw 0;
	BitLen = len;
	MemLen = int(ceil(float(BitLen) / 32.0));
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
		pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{	

	pMem = new TELEM[bf.MemLen];
	MemLen = bf.MemLen;
	BitLen = bf.BitLen;
	for (int i = 0; i < MemLen; i++)
		pMem[i] = bf.pMem[i];

}

TBitField::~TBitField()
{
	MemLen = NULL;
	pMem = NULL;
	delete[]pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << n % (sizeof(TELEM) * 8);

}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n < 0)
		throw 0;

	if (n >= BitLen)
		throw 1;
	pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n < 0)
		throw 0;

	if (n >= BitLen)
		throw 1;

	int Bait = int(float(n) / 32);
	int Bit = int(n - Bait * 32);
	int Maska = 1 << Bit;
	int neMaska = !Maska;
	pMem[Bait] = pMem[Bait] & neMaska;
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n < 0)
		throw 0;

	if (n >= BitLen)
		throw 1;

  return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	TBitField UUUUU(bf);
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	TBitField UUUUU(bf);
	return UUUUU;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	TBitField UUUUU(bf);
	return UUUUU;
}

TBitField TBitField::operator~(void) // отрицание
{
	return *this;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	return ostr;
}
