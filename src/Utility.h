/* The MIT License

   Copyright (c) 2009 Genome Research Ltd (GRL), 2010 Broad Institute

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

/* Contact: Fan Zhang <fanzhang@umich.edu> */
#ifndef UTILITY_
#define UTILITY_

#include  <string>
#include  <unordered_map>
#include <vector>
#include <fstream>

class _GCstruct
{
public:
	unsigned char* GC;
	unsigned int len;
	_GCstruct( unsigned int length)
	{
		len=length;
		GC= new unsigned char [len];
	}
	_GCstruct( )
	{
		len=0;
		GC=0;
	}
	~_GCstruct()
	{
		if(GC!=0)
		{
		delete [] GC;
		}
	}
	void write(std::ofstream& fout)
	{
		fout.write((char*)this,sizeof(_GCstruct));
		fout.write((char*) this->GC, this->len*sizeof(unsigned char));
	}
	void read(std::ifstream & fin)
	{
		fin.read((char*)this,sizeof(_GCstruct));
		this->GC = new unsigned char [this->len];
		fin.read((char*) this->GC, this->len*sizeof(unsigned char));
	}
};



class ContigStatus
{
public:
	 ContigStatus()
	{
		name="default";
		length=0;
		numOverlappedReads=0;
		numPairOverlappedReads=0;
		numFullyIncludedReads=0;
		numFullyIncludedPairedReads=0;
	}
	 ContigStatus(std::string chr, int len)
	{
		name=chr;
		length=len;
		numOverlappedReads=0;
		numPairOverlappedReads=0;
		numFullyIncludedReads=0;
		numFullyIncludedPairedReads=0;
	}
	 ~ContigStatus()
	 {

	 }
	 int addNumOverlappedReads()
	 {
		 numOverlappedReads++;
		 return 0;
	 }
	 int addNumPairOverlappedReads()
	 {
		 numPairOverlappedReads++;
		 return 0;
	 }
	 int addNumFullyIncludedReads()
	 {
		 numFullyIncludedReads++;
		 return 0;
	 }
	 int addNumFullyIncludedPairedReads()
	 {
		 numFullyIncludedPairedReads++;
		 return 0;
	 }
	 int getNumOverlappedReads()
	 {

		 return 		 numOverlappedReads;
	 }
	 int getNumPairOverlappedReads()
	 {

		 return 		 numPairOverlappedReads++;
	 }
	 int getNumFullyIncludedReads()
	 {

		 return 		 numFullyIncludedReads++;
	 }
	 int getNumFullyIncludedPairedReads()
	 {

		 return 		 numFullyIncludedPairedReads++;
	 }
	 std::string getName()
	 {
		 return name;
	 }
	 int getLength()
	 {
		 return length;
	 }
private:
		std::string name;
		int length;
		int numOverlappedReads;
		int numPairOverlappedReads;//same contig
		int numFullyIncludedReads;
		int numFullyIncludedPairedReads;//same contig
};

#endif /* UTILITY_ */
