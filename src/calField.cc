double calField(double currI, double pos){
  /*
    Function to calculate magnetic field generated by anti-helmholtz 
    coil with given current currI and absolute positon pos;
    return field at a single position
    by Yu 2016/11/20
  */
  
  double field;
  double u0 = 1.256637e-6; // Magnetic constant
  field = u0 * currI * geoR**2 * 0.5 / (((pos - frontCoil)**2 + geoR**2 )**(3/2) - ((pos - backCoil)**2 + geoR**2 )**(3/2));
  return(field);
}
  
