//not able to fix, bugs at 2 locs
int buggyQ(int inhibit, int up_sep, int down_sep){
  int bias;
  if(inhibit) {
    bias = up_sep; //bug  up_sep + 10
  }
  else {
    bias = up_sep;
  }
  if (bias < down_sep) //bug  bias > down_sep
    return 1;  
  else    
    return 0;
}

int mainQ(int inhibit, int up_sep, int down_sep){
  return buggyQ(inhibit, up_sep, down_sep);
}

void main(int argc, char* argv[]){
  printf("%d\n",mainQ(atoi(argv[1]), atoi(argv[2]),atoi(argv[3])));
}
