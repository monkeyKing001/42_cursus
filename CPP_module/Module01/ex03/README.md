### member class by Reference vs Pointer
## HumanA -> Reference
1. need initializer for constructor
초기화 리스트는 객체의 생성 후 값을 대입하는 것이 아닌, 객체의 생성과 동시에 값을 지정할 수 있게 한다. 이렇게 초기화 리스트를 사용하는 것은 direct initialization 또는 uniform initialization으로 초기화하는 것과 거의 동일하다.
```cpp
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
```
2. access weapon class's member fun with .
```cpp
getWeapon().getType() 
```

## HumannB -> Pointer
1. don't need initializer (NULLABLE)
2. access weapon class's member fun with ->
```cpp
getWeapon() -> getType() 
```
