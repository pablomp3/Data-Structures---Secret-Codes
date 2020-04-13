#include <iostream>
#include <queue>

using namespace std;
typedef int Dato;


class DoubleNode{
protected:
    //DoubleNode* backward;
public:
    char dato;

    Dato freq;
    Dato parent_freq;
    //string code;
    DoubleNode* first;
    DoubleNode* second;

    DoubleNode(char dato, Dato freq)
    {
        this->dato = dato;
        this->freq = freq;
        //this->code = "";
        //this->parent_freq = parent_freq;
        this->first = this->second = NULL;
    }

    char Nodedato() const{return dato;}
    void putdato(char a) {this->dato = a;}
    //void putcode(string a) {this->code = a;}
    Dato Nodefreq() const{return freq;}
    void putfreq(int a) {this->freq = a;}
    Dato Nodeparentfreq() const{return parent_freq;}

    DoubleNode* firstchild() {
        return this->first;
    }
    DoubleNode* secondchild() {
        return this->second;
    }

    void putparentfreq(int a){
        this->parent_freq = a;
    }
    void putfirst(DoubleNode* a){
        this->first = a;
    }
    void putsecond(DoubleNode* a){
        this->second = a;
    }

friend class Tree;
};
//------------- Functions ----------------------------------
void build_tree(int arr_freq[], char arr_letter[], int size_arr, int index){

    // create array of nodes
    DoubleNode *arr_nodes[size_arr];
    for(int i=0; i<size_arr; i++){
        arr_nodes[i] = new DoubleNode(arr_letter[i], arr_freq[i]);
        //cout << arr_nodes[i]->Nodedato() << ", ";
    }

    //cout << endl;
    // create parent node
    //DoubleNode *parent = new DoubleNode(NULL, arr_nodes[i]->Nodefreq()+arr_nodes[i+1]->Nodefreq());
    //parent->putfirst(arr_nodes[i]);
    //parent->putsecond(arr_nodes[i+1]);

    //DoubleNode *parent = new DoubleNode(NULL, arr_freq[index]+arr_freq[index+1]);

    // create child nodes
    //DoubleNode *leaf0 = new DoubleNode(arr_letter[index], arr_freq[index]);
    //DoubleNode *leaf1 = new DoubleNode(arr_letter[index+1], arr_freq[index+1]);
}


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], char err[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];
    char L1[n1], R1[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        L1[i] = err[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        R1[j] = err[m + 1 + j];
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            err[k] = L1[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            err[k] = R1[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        err[k] = L1[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        err[k] = R1[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], char err[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, err, l, m);
        mergeSort(arr, err, m+1, r);

        merge(arr, err, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << A[i] << ", ";
    cout << endl;
}

void printArraychar(char A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << A[i] << ", ";
    cout << endl;
}
//------------------ modify merge sort functions for code ---------------------------
// change merge sort for bubble sort
void bubbleSort_node(DoubleNode *arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j]->Nodefreq() > arr[j+1]->Nodefreq())
        {
           swap(arr[j], arr[j+1]);
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}
// arr == freq
// err == char
void merge_node(DoubleNode *arr_nodes[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];
    //char L1[n1], R1[n2];
    //DoubleNode *first1[n1], *first2[n2];
    //DoubleNode *second1[n1], *second2[n2];
    //DoubleNode *L[n1], *R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = arr_nodes[l+i]->Nodefreq();
        //L1[i] = arr_nodes[l+i]->Nodedato();
        //first1[i] = arr_nodes[l+i]->firstchild();
        //second1[i] = arr_nodes[l+i]->secondchild();
    }
    for (j = 0; j < n2; j++){
        R[j] = arr_nodes[m+1+j]->Nodefreq();
        //R1[j] = arr_nodes[m+1+j]->Nodedato();
        //first2[j] = arr_nodes[m+1+j]->firstchild();
        //second2[j] = arr_nodes[m+1+j]->secondchild();
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr_nodes[k]->putfreq(L[i]);
            //arr_nodes[k]->putdato(L1[i]);
            //arr_nodes[k]->putfirst(first1[i]);
            //arr_nodes[k]->putsecond(second1[i]);
            i++;
        }
        else
        {
            arr_nodes[k]->putfreq(R[j]);
            //arr_nodes[k]->putdato(R1[j]);
            //arr_nodes[k]->putfirst(first2[j]);
            //arr_nodes[k]->putsecond(second2[j]);
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr_nodes[k]->putfreq(L[i]); //arr[k] = L[i];
        //arr_nodes[k]->putdato(L1[i]); //err[k] = L1[i];
        //arr_nodes[k]->putfirst(first1[i]);
        //arr_nodes[k]->putsecond(second1[i]);
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr_nodes[k]->putfreq(R[j]); //arr[k] = R[j];
        //arr_nodes[k]->putdato(R1[j]); //err[k] = R1[j];
        //arr_nodes[k]->putfirst(first2[j]);
        //arr_nodes[k]->putsecond(second2[j]);
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort_node(DoubleNode *arr_nodes[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort_node(arr_nodes, l, m);
        mergeSort_node(arr_nodes, m+1, r);

        merge_node(arr_nodes, l, m, r);
    }
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
string letters;
string arr_codes[26];

void traverse(DoubleNode *current, string path)
{

    if (current->first==NULL and current->second==NULL){ //the current node is a leaf (character)
        //imprimir todo el coso
        //cout << current->Nodedato() << ": " << path << endl;
        arr_codes[letters.length()] = path;
        letters += current->Nodedato();
        return;
    }

    else{
    //cout << "node [" << current->Nodefreq() << "," << current->Nodedato() << "]";
    //cout << ", first child [" << current->firstchild()->Nodefreq() << "," << current->firstchild()->Nodedato()
         //<< "], second child [" << current->secondchild()->Nodefreq() << "," << current->secondchild()->Nodedato() << "]" << endl;

    traverse(current->firstchild(), path+"0");
    //after return:
    traverse(current->secondchild(), path+"1");
    }
}

void HuffmanCodes(DoubleNode *arr_nodos[], int size, int frequency_parent){

    //------ interchange internal node by character node in case of having the same frequency --------------
    for(int i=1; i<size; i++){
        if (arr_nodos[i-1]->Nodefreq()==arr_nodos[i]->Nodefreq()){
            if(arr_nodos[i-1]->Nodedato()=='$' and arr_nodos[i]->Nodedato()!='$'){
                swap(arr_nodos[i-1],arr_nodos[i]);
                //cout << "si" << endl;
                for(int j=0; j<size; j++){
                    if (arr_nodos[j]->Nodedato()=='$'); //cout << arr_nodos[j]->Nodedato() << "(" << arr_nodos[j]->first->Nodedato() << ", " << arr_nodos[j]->second->Nodedato() << "), ";
                    else; //cout << arr_nodos[j]->Nodedato() << ", ";

                }
                //cout << endl;
                for(int j=0; j<size; j++){
                    //cout << arr_nodos[j]->Nodefreq() << ", ";
                }
                //cout << endl;
            }
        }
        else; //cout << "no" << endl;
    }
    //cout << "que" << endl;

    for(int i=1; i<size; i++){
        if (arr_nodos[i-1]->Nodefreq()==arr_nodos[i]->Nodefreq()){
            if(arr_nodos[i-1]->Nodedato()=='$' and arr_nodos[i]->Nodedato()!='$'){
                swap(arr_nodos[i-1],arr_nodos[i]);
                //cout << "si2" << endl;
                for(int j=0; j<size; j++){
                    //cout << arr_nodos[j]->Nodedato() << ", ";
                    if (arr_nodos[j]->Nodedato()=='$'); //cout << arr_nodos[j]->Nodedato() << "(" << arr_nodos[j]->first->Nodedato() << ", " << arr_nodos[j]->second->Nodedato() << "), ";
                    else; //cout << arr_nodos[j]->Nodedato() << ", ";
                }
                //cout << endl;
                for(int j=0; j<size; j++){
                    //cout << arr_nodos[j]->Nodefreq() << ", ";
                }
                //cout << endl;
            }
        }
        else; //cout << "no2" << endl;
    }

    for(int i=1; i<size; i++){
        if (arr_nodos[i-1]->Nodefreq()==arr_nodos[i]->Nodefreq()){
            if(arr_nodos[i-1]->Nodedato()=='$' and arr_nodos[i]->Nodedato()!='$'){
                swap(arr_nodos[i-1],arr_nodos[i]);
                //cout << "si3" << endl;
                for(int j=0; j<size; j++){
                    if (arr_nodos[j]->Nodedato()=='$'); //cout << arr_nodos[j]->Nodedato() << "(" << arr_nodos[j]->first->Nodedato() << ", " << arr_nodos[j]->second->Nodedato() << "), ";
                    else; //cout << arr_nodos[j]->Nodedato() << ", ";
                }
                //cout << endl;
                for(int j=0; j<size; j++){
                    //cout << arr_nodos[j]->Nodefreq() << ", ";
                }
                //cout << endl;
            }
        }
        else; //cout << "no3" << endl;
    }

    for(int i=1; i<size; i++){
        if (arr_nodos[i-1]->Nodefreq()==arr_nodos[i]->Nodefreq()){
            if(arr_nodos[i-1]->Nodedato()=='$' and arr_nodos[i]->Nodedato()=='$' and frequency_parent==arr_nodos[i-1]->Nodefreq()){
                swap(arr_nodos[i-1],arr_nodos[i]);
                //cout << "si4" << endl;
                for(int j=0; j<size; j++){
                    if (arr_nodos[j]->Nodedato()=='$'); //cout << arr_nodos[j]->Nodedato() << "(" << arr_nodos[j]->first->Nodedato() << ", " << arr_nodos[j]->second->Nodedato() << "), ";
                    else; //cout << arr_nodos[j]->Nodedato() << ", ";
                }
                //cout << endl;
                for(int j=0; j<size; j++){
                    //cout << arr_nodos[j]->Nodefreq() << ", ";
                }
                //cout << endl;
            }
        }
        else; //cout << "no4" << endl;
    }
    //---------------------------------------------------------------------------
    // take the first two nodes and sum their frequencies, make their parent

    DoubleNode *parent = new DoubleNode('$',arr_nodos[0]->Nodefreq()+arr_nodos[1]->Nodefreq());
    parent->putfirst(arr_nodos[0]);
    //cout << "parent " << parent->Nodefreq() << " points to " << parent->firstchild()->Nodedato() << " (0) freq" << parent->firstchild()->Nodefreq() << endl;
    parent->putsecond(arr_nodos[1]);
    //cout << "parent " << parent->Nodefreq() << " points to " << parent->secondchild()->Nodedato() << " (1) freq" << parent->secondchild()->Nodefreq() << endl;

    // if the parent is the root, we call traverse and finish the function
    // array of nodes with the parent
    //cout << "array of nodes with the parent:" << endl;
    DoubleNode *arr_nodos_next[size-1]; //the array reduces its size 1 cell
    arr_nodos_next[0] = parent;
    int freq_parent = parent->Nodefreq();
    for(int i=1; i<size-1; i++){
        arr_nodos_next[i]=arr_nodos[i+1];
    }
    for(int i=0; i<size-1; i++){
        if (arr_nodos_next[i]->Nodedato()=='$'); //cout << arr_nodos_next[i]->Nodedato() << "(" << arr_nodos_next[i]->first->Nodedato() << ", " << arr_nodos_next[i]->second->Nodedato() << "), ";
        else; //cout << arr_nodos_next[i]->Nodedato() << ", ";
    }
    //cout << "  size: " << size-1 << endl;
    for(int i=0; i<size-1; i++){
        //cout << arr_nodos_next[i]->Nodefreq() << ", ";
    }
    //cout << "  size: " << size-1 << endl << endl;

    //cout << "parent " << arr_nodos_next[0]->Nodefreq() << " still points to " << arr_nodos_next[0]->firstchild()->Nodedato() << " (0) freq" << arr_nodos_next[0]->firstchild()->Nodefreq() << endl;
    //cout << "parent " << parent->Nodefreq() << " still points to " << parent->firstchild()->Nodedato() << " (0) freq" << parent->firstchild()->Nodefreq() << endl;
    //cout << "parent " << arr_nodos_next[0]->Nodefreq() << " still points to " << arr_nodos_next[0]->secondchild()->Nodedato() << " (1) freq" << arr_nodos_next[0]->secondchild()->Nodefreq() << endl;
    //cout << "parent " << parent->Nodefreq() << " still points to " << parent->secondchild()->Nodedato() << " (1) freq" << parent->secondchild()->Nodefreq() << endl;

    bubbleSort_node(arr_nodos_next,size-1);

    for(int i=0; i<size-1; i++){
        if (arr_nodos_next[i]->Nodedato()=='$'); //cout << arr_nodos_next[i]->Nodedato() << "(" << arr_nodos_next[i]->first->Nodedato() << ", " << arr_nodos_next[i]->second->Nodedato() << "), ";
        else;//cout << arr_nodos_next[i]->Nodedato() << ", ";
    }
    //cout << "  size: " << size-1 << endl;
    for(int i=0; i<size-1; i++){
        //cout << arr_nodos_next[i]->Nodefreq() << ", ";
    }
    //cout << endl << "after sorting the array of nodes the parent node changes: " << endl;
    //cout << "parent " << arr_nodos_next[0]->Nodefreq() << " still points to " << arr_nodos_next[0]->firstchild()->Nodedato() << " (0) freq" << arr_nodos_next[0]->firstchild()->Nodefreq() << endl;
    //cout << "parent " << parent->Nodefreq() << " still points to " << parent->firstchild()->Nodedato() << " (0) freq" << parent->firstchild()->Nodefreq() << endl;
    //cout << "parent " << arr_nodos_next[0]->Nodefreq() << " still points to " << arr_nodos_next[0]->secondchild()->Nodedato() << " (1) freq" << arr_nodos_next[0]->secondchild()->Nodefreq() << endl;
    //cout << "parent " << parent->Nodefreq() << " still points to " << parent->secondchild()->Nodedato() << " (1) freq" << parent->secondchild()->Nodefreq() << endl;


    size = size-1;
    //cout << "next size: " << size << endl;
    if (size==1){
        //traverse(arr_nodos_next[0],"");
        traverse(parent,"");
        return;
    }
    HuffmanCodes(arr_nodos_next,size,freq_parent);
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------- Global variables ---------------------------
string uno, todo;
int count_a, unique_a,
    count_b, unique_b,
    count_c, unique_c,
    count_d, unique_d,
    count_e, unique_e,
    count_f, unique_f,
    count_g, unique_g,
    count_h, unique_h,
    count_i, unique_i,
    count_j, unique_j,
    count_k, unique_k,
    count_l, unique_l,
    count_m, unique_m,
    count_n, unique_n,
    count_o, unique_o,
    count_p, unique_p,
    count_q, unique_q,
    count_r, unique_r,
    count_s, unique_s,
    count_t, unique_t,
    count_u, unique_u,
    count_v, unique_v,
    count_w, unique_w,
    count_x, unique_x,
    count_y, unique_y,
    count_z, unique_z = 0;
int unique_letters, index = 0;
//----------------------------------------------------------

int main()
{
    /*3,hello
    have a nice day
    love is in the air
    have some oranges*/

    int lineas;
    cin >> lineas;

    char comma;
    cin >> comma;

    string word;
    cin >> word;

    cin.ignore();

    for (int i=0; i<lineas; i++){
        getline(cin,uno);
        todo = todo + uno;
    }

    //array inicial con letras unicas pero sparse
    char init_array[todo.size()];
    for (int j=0; j<todo.size(); j++){ //find the # of unique letters in the text
            if(todo[j]=='a' and unique_a==0) {unique_letters++; unique_a++; init_array[j]='a';}
            else if(todo[j]=='b' and unique_b==0) {unique_letters++; unique_b++; init_array[j]='b';}
            else if(todo[j]=='c' and unique_c==0) {unique_letters++; unique_c++; init_array[j]='c';}
            else if(todo[j]=='d' and unique_d==0) {unique_letters++; unique_d++; init_array[j]='d';}
            else if(todo[j]=='e' and unique_e==0) {unique_letters++; unique_e++; init_array[j]='e';}
            else if(todo[j]=='f' and unique_f==0) {unique_letters++; unique_f++; init_array[j]='f';}
            else if(todo[j]=='g' and unique_g==0) {unique_letters++; unique_g++; init_array[j]='g';}
            else if(todo[j]=='h' and unique_h==0) {unique_letters++; unique_h++; init_array[j]='h';}
            else if(todo[j]=='i' and unique_i==0) {unique_letters++; unique_i++; init_array[j]='i';}
            else if(todo[j]=='j' and unique_j==0) {unique_letters++; unique_j++; init_array[j]='j';}
            else if(todo[j]=='k' and unique_k==0) {unique_letters++; unique_k++; init_array[j]='k';}
            else if(todo[j]=='l' and unique_l==0) {unique_letters++; unique_l++; init_array[j]='l';}
            else if(todo[j]=='m' and unique_m==0) {unique_letters++; unique_m++; init_array[j]='m';}
            else if(todo[j]=='n' and unique_n==0) {unique_letters++; unique_n++; init_array[j]='n';}
            else if(todo[j]=='o' and unique_o==0) {unique_letters++; unique_o++; init_array[j]='o';}
            else if(todo[j]=='p' and unique_p==0) {unique_letters++; unique_p++; init_array[j]='p';}
            else if(todo[j]=='q' and unique_q==0) {unique_letters++; unique_q++; init_array[j]='q';}
            else if(todo[j]=='r' and unique_r==0) {unique_letters++; unique_r++; init_array[j]='r';}
            else if(todo[j]=='s' and unique_s==0) {unique_letters++; unique_s++; init_array[j]='s';}
            else if(todo[j]=='t' and unique_t==0) {unique_letters++; unique_t++; init_array[j]='t';}
            else if(todo[j]=='u' and unique_u==0) {unique_letters++; unique_u++; init_array[j]='u';}
            else if(todo[j]=='v' and unique_v==0) {unique_letters++; unique_v++; init_array[j]='v';}
            else if(todo[j]=='w' and unique_w==0) {unique_letters++; unique_w++; init_array[j]='w';}
            else if(todo[j]=='x' and unique_x==0) {unique_letters++; unique_x++; init_array[j]='x';}
            else if(todo[j]=='y' and unique_y==0) {unique_letters++; unique_y++; init_array[j]='y';}
            else if(todo[j]=='z' and unique_z==0) {unique_letters++; unique_z++; init_array[j]='z';}
            else init_array[j]=' ';
        }
    //cout << "number of unique letter: " << unique_letters << endl;

    // count number of each letter
    //cout << todo << endl;
    for (int j=0; j<todo.size(); j++){
            if(todo[j]=='a') count_a++;
            if(todo[j]=='b') count_b++;
            if(todo[j]=='c') count_c++;
            if(todo[j]=='d') count_d++;
            if(todo[j]=='e') count_e++;
            if(todo[j]=='f') count_f++;
            if(todo[j]=='g') count_g++;
            if(todo[j]=='h') count_h++;
            if(todo[j]=='i') count_i++;
            if(todo[j]=='j') count_j++;
            if(todo[j]=='k') count_k++;
            if(todo[j]=='l') count_l++;
            if(todo[j]=='m') count_m++;
            if(todo[j]=='n') count_n++;
            if(todo[j]=='o') count_o++;
            if(todo[j]=='p') count_p++;
            if(todo[j]=='q') count_q++;
            if(todo[j]=='r') count_r++;
            if(todo[j]=='s') count_s++;
            if(todo[j]=='t') count_t++;
            if(todo[j]=='u') count_u++;
            if(todo[j]=='v') count_v++;
            if(todo[j]=='w') count_w++;
            if(todo[j]=='x') count_x++;
            if(todo[j]=='y') count_y++;
            if(todo[j]=='z') count_z++;
    }

    // create array with the required # of spaces
    int index[unique_letters];
    char charac[unique_letters];

    int init=0;
    for(int i=0; i<todo.size();i++){
        //cout << init_array[i] << ", ";
        if (init_array[i]!=' '){
            charac[init]=todo[i];
            if (todo[i]=='a') index[init]=count_a;
            else if (todo[i]=='b') index[init]=count_b;
            else if (todo[i]=='c') index[init]=count_c;
            else if (todo[i]=='d') index[init]=count_d;
            else if (todo[i]=='e') index[init]=count_e;
            else if (todo[i]=='f') index[init]=count_f;
            else if (todo[i]=='g') index[init]=count_g;
            else if (todo[i]=='h') index[init]=count_h;
            else if (todo[i]=='i') index[init]=count_i;
            else if (todo[i]=='j') index[init]=count_j;
            else if (todo[i]=='k') index[init]=count_k;
            else if (todo[i]=='l') index[init]=count_l;
            else if (todo[i]=='m') index[init]=count_m;
            else if (todo[i]=='n') index[init]=count_n;
            else if (todo[i]=='o') index[init]=count_o;
            else if (todo[i]=='p') index[init]=count_p;
            else if (todo[i]=='q') index[init]=count_q;
            else if (todo[i]=='r') index[init]=count_r;
            else if (todo[i]=='s') index[init]=count_s;
            else if (todo[i]=='t') index[init]=count_t;
            else if (todo[i]=='u') index[init]=count_u;
            else if (todo[i]=='v') index[init]=count_v;
            else if (todo[i]=='w') index[init]=count_w;
            else if (todo[i]=='x') index[init]=count_x;
            else if (todo[i]=='y') index[init]=count_y;
            else if (todo[i]=='z') index[init]=count_z;
            init++;
        }
    }
    //printArraychar(charac, unique_letters);
    //printArray(index, unique_letters);
    mergeSort(index, charac, 0, unique_letters - 1);
    //printArraychar(charac, unique_letters);
    //printArray(index, unique_letters);
    //cout << endl;
    int size = sizeof(charac) / sizeof(charac[0]);

    //convert to a node array in order to build the tree
    //cout << "array de nodos: ";
    DoubleNode *arr_nodes[unique_letters];
    for(int i=0; i<unique_letters; i++){
        arr_nodes[i] = new DoubleNode(charac[i], index[i]);
        //cout << arr_nodes[i]->Nodedato() << ", ";
    }
    //cout << endl << "array de freqs: ";
    for(int i=0; i<unique_letters; i++){
        //cout << arr_nodes[i]->Nodefreq() << ", ";
    }
    //cout << endl;

    /*
    //char arr[] = { '$', 'b', 'c', 'd', '$', 'f' };
    //int freq[] = { 1, 1, 1, 1, 1, 1 };
    char arr[] = { 'b', '$', 'f', 'a', '$', 'a' };
    int freq[] = { 1, 1, 1, 2, 2, 3 };
    cout << "array de nodos prueba: ";
    DoubleNode *arr_nodes1[6];
    for(int i=0; i<6; i++){
        arr_nodes1[i] = new DoubleNode(arr[i], freq[i]);
        cout << arr_nodes1[i]->Nodedato() << ", ";
    }
    cout << endl << "array de freqs prueba: ";
    for(int i=0; i<6; i++){
        //arr_nodes1[i] = new DoubleNode(arr[i], freq[i]);
        cout << arr_nodes1[i]->Nodefreq() << ", ";
    }
    cout << endl;*/

    HuffmanCodes(arr_nodes, size,0);

    //cout << endl << "Tree is built. Let's traverse it" << endl;

    for (int i=0; i<word.length(); i++){
        //cout << word[i] << ", ";
        for (int j=0; j<letters.length(); j++){
            //cout << letters[j] << ", ";
            if (word[i]==letters[j]) cout << arr_codes[j];
        }
    }
    cout << endl;
    //cout << word << endl;
    for (int i=0; i<letters.length(); i++){
        //cout << letters[i] << " " << arr_codes[i] << endl;
    }


    return 0;
}
