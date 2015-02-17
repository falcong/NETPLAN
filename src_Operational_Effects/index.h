// --------------------------------------------------------------
//    NETSCORE Version 1
//    index.h -- Definition of index functions
//    2009-2010 (c) Eduardo Ib��ez
//    2011-2014 (c) Venkat Krishnan (VK)
// --------------------------------------------------------------

#ifndef _INDEX_H_
#define _INDEX_H_

// Declare class type to hold index information
class Index {
    public:
        Index();
        Index(const Index& rhs);
        ~Index();
        Index& operator=(const Index& rhs);
		
		vector<int> GetPosition() const;
		vector<int> GetColumn() const;
		vector<int> GetYear() const;
		vector<string> GetName() const;
		int GetPosition(const int idx) const;
		int GetColumn(const int idx) const;
		int GetYear(const int idx) const;
		string GetName(const int idx) const;
		int GetSize() const;
		
		void Add(const int idx, const int col, const string& name);
		void Add(const int idx, const int col, const int year, const string& name);
		void Add(const int idx, const Step& col, const string& name);
		void WriteFile(const char* fileinput) const;
		
    private:
		vector<int> Position;
		vector<int> Column;
		vector<int> Year;
		vector<string> Name;
};

Index ReadFile(const char* fileinput);
void ImportIndices();

#endif  // _INDEX_H_
