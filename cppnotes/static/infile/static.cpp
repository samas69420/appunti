static int s_var = 69; // s_var will exist and be 69 only in this translation unit

//int s_var = 69; // to use this, "extern" for declaration in main is needed
//                // declarations without extern leads to linking error (multiple defs)
