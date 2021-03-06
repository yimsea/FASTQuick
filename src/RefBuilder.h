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
#ifndef REFBUILDER_H_
#define REFBUILDER_H_
#include "Utility.h"
#include "../libbwa/bwtaln.h"

class RefBuilder
{
public:
	std::vector<std::string> SeqVec;
	std::unordered_map<std::string,uint32_t > RefTableIndex;
	//unordered_map<string,bool> longRefTable;
	RefBuilder();
	RefBuilder(const std::string& VcfPath, const std::string& RefPath, const std::string& NewRefPath, const std::string& DBsnpPath, const std::string& MaskPath, const gap_opt_t* opt, bool reselect);//, std::unordered_map<std::string,bool>& longRefTable);
	virtual ~RefBuilder();
};

#endif /* REFBUILDER_H_ */
