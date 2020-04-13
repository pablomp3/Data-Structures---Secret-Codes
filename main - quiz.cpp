#include <iostream>

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
string letters;
string arr_codes[26];
//---------------------------------------------------------

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
    /*cout << "array de nodos: ";
    DoubleNode *arr_nodes[unique_letters];
    for(int i=0; i<unique_letters; i++){
        arr_nodes[i] = new DoubleNode(charac[i], index[i]);
        cout << arr_nodes[i]->Nodedato() << ", ";
    }
    cout << endl << "array de freqs: ";
    for(int i=0; i<unique_letters; i++){
        cout << arr_nodes[i]->Nodefreq() << ", ";
    }
    cout << endl;*/

    //cout << "array de nodos: ";
    for(int i=0; i<unique_letters; i++){
        //cout << charac[i] << ", ";
    }
    //cout << endl << "array de freqs: ";
    for(int i=0; i<unique_letters; i++){
        //cout << index[i] << ", ";
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

    //HuffmanCodes(arr_nodes, size,0);

    //cout << endl << "Tree is built. Let's traverse it" << endl;

    for (int i=0; i<unique_letters; i++){
        //cout << word[i] << ", ";
        for (int j=0; j<word.length(); j++){
            //cout << letters[j] << ", ";
            if (charac[i]==word[j]) cout << word[j];
        }
    }
    cout << endl;
    //cout << word << endl;
    //for (int i=0; i<charac.length(); i++){
        //cout << letters[i] << " " << arr_codes[i] << endl;
    //}


    return 0;
}
