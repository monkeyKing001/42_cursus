# reference vs pointer

## in use


| category | pointer | reference |
| :--: | :--: | :--: |
| assign | `int a = 10, int *pa =  &a` | int a = 10, int &ra  = a |
| NULLABLE | NULLABLE | UNABLE |
| address | &a != &pa | &a == &ra |
| valuse | a = 10, pa = 0x00...0a | a = 10, ra = 10 |
| access | can access from pa(0x00...0a) to everywhere(0xff...ff ~ 0x00...00) | can access only ref |
| register | use 1 register | use 1 register |
### reference
