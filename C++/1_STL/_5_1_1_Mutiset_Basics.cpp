//it can contain duplicate values just like multi_map 
//BUT , time complexity here for operations of insertion,find ..... is O(logN) .

// USAGE : we can use it as an alternative of priority queue .

// if a duplicate value is deeted by using the iterator then the first value will be deleted and rest duplicate values remains as in this case find() function return the 'it' of first element .
//BUT , if it is deleted by s.erase("abc"); then all duplicate values will be deleted .