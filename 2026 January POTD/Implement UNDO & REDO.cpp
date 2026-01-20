class Solution {
  public:
    string undo_buffer = "";
    string str;
    void append(char x) {
        // append x into document
        str.push_back(x);
        
    }

    void undo() {
        // undo last change
        if(str.empty())return;
        undo_buffer.push_back(str.back());
        str.pop_back();
    }

    void redo() {
        // redo changes
        if(undo_buffer.empty())return;
        str.push_back(undo_buffer.back());
        undo_buffer.pop_back();
    }

    string read() {
        // read the document
        return str;
    }
};
