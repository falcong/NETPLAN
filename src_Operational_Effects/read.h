// --------------------------------------------------------------
//    NETSCORE Version 1
//    read.h -- Definition of reading functions
//    2009-2010 (c) Eduardo Ib��ez
//    2011-2014 (c) Venkat Krishnan (VK)
// --------------------------------------------------------------

#ifndef _READ_H_
#define _READ_H_

#include "node.h"
#include "arc.h"

void ReadParameters(const char* fileinput);
vector<Node> ReadListNodes(const char* fileinput);
vector<Arc> ReadListArcs(const char* fileinput);
MatrixStr ReadStep(const char* fileinput);
MatrixStr ReadProperties(const char* fileinput, const string& defvalue, const int num_fields);
void ReadTrans(vector<Node>& Nodes, vector<Arc>& Arcs, const char* fileinput);
void ReadEvents(double output[], const char* fileinput);

#endif  // _READ_H_
