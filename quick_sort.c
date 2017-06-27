
int separa (int v[], int p, int r)
{
   int c = v[p], i = p+1, j = r, t;
   while (/*A*/ i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j;
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   // agora i == j+1
   v[p] = v[j], v[j] = c;
   return j;
}

void quickSort (int v[], int p, int r)
{
   int j;
   while (p < r) {
      j = separa (v, p, r);
      if (j - p < r - j) {
         quickSort (v, p, j-1);
         p = j + 1;
      } else {
         quickSort (v, j+1, r);
         r = j - 1;
      }
   }
}
