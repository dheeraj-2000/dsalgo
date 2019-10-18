long long int floorSqrt(long long int x) {
      long long int i;
      for(i=1;i*i<=x;i++);
      return i-1;
}
