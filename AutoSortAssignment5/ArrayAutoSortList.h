// Setting up the AutoSortList class

class AutoSortList{
    public:
        AutoSortList(int initialSize);
        bool add(int value);
        bool remove(int value);
        int peek(int value);
    private:
        int *internalStorage;
        int endOfList;
        int size;        
};