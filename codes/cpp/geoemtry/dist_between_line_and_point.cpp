
double dist_line_podouble(double x1, double y1, double x2, double y2, double px, double py){
  double num = abs((py-y1)*(x2-x1) - (y2-y1)*(px-x1));
  double den = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  return num/den;
}
