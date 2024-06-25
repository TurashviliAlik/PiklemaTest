Сборка (проверялось на Qt 5.15.14):
```
path/to/qmake PiklemaTest.pro -spec linux-g++ CONFIG+=release CONFIG+=qtquickcompiler 
make qmake_all
make -j16
```
Либо через Qt Creator
