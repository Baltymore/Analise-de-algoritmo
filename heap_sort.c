
#define troca (A, B) { int t = A; A = B; B = t; }
rt
void constroiHeap (int m, int v[])
{
   int k;
   for (k = 1; k < m; ++k) {
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (v[f/2], v[f]);          // 6
         f /= 2;                        // 7
      }
   }
}


void peneira (int m, int v[])
{
   int p = 1, f = 2, t = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1])  ++f;
      if (t >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = t;
}


void heapsort (int n, int v[])
{
   int m;
   constroiHeap (n, v);
   for (m = n; m >= 2; --m) {
      troca (v[1], v[m]);
      peneira (m-1, v);
   }
}
