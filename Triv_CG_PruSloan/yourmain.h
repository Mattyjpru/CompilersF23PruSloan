int yourmain() {
SR -= 4;
R[1] = 0;
F23_Time += 1;
Mem[SR + 0] = R[1];
F23_Time += 20 + 1;
print_int(Mem[SR + 0]);
F23_Time += 20 + 1;
SR += 4;
return 0;
}