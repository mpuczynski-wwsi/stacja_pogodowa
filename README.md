# Napisać program według poniższego opisu.

Meteorologiczna stacja pomiarowa zbiera i zapamiętuje dane dotyczące następujących parametrów pogody: temperatura powietrza, prędkość wiatru,
kierunek wiatru, wielkość opadów, ciśnienie i inne.  Dane te są zapamiętywane co pewien, ustalony z góry czas, np. godzinę, dobę.

**Wymagania:**

W programie, dane (czyli ciągi liczb reprezentujących wyniki pomiarów parametrów pogody) powinny być pamiętane w tablicach.
Należy wybrać **3** parametry pogody, dla każdego z nich utworzyć osobną tablicę.

Program ma realizować **6** funkcjonalności:

-   **Dwie** funkcjonalności związane z wprowadzaniem danych:

1.  Użytkownik może wprowadzać dane z klawiatury,
2.  Dane generowane są losowo.

-   **Cztery** funkcjonalności związane z przetwarzaniem informacji, z których (przynajmniej) jedna powinna zostać zaproponowana przez studenta,
-   a (co najwyżej) trzy powinny zostać wybrane spośród propozycji podanych w poniższym zestawieniu.
-   W zestawieniu tym parametr pogody jest oznaczony przez _p_.

-   Funkcjonalności związane przetwarzaniem informacji:

1.  Wyznaczyć dzień (albo godzinę), w którym wartość _p_ jest największa (albo najmniejsza);
2.  Sprawdzić, czy w podanym przedziale czasu wartości _p_ tworzą ciąg rosnący (albo malejący);
3.  Znaleźć najzimniejszy (albo najcieplejszy dzień) wśród dni o maksymalnej (albo minimalnej) wartości jednego wybranego _p_ (innego niż temperatura),
    np. najzimniejszy dzień wśród dni o sile wiatru przekraczającej f;
4.  Obliczyć dwie wartości średnie (arytmetyczną, geometryczną, harmoniczną, potęgową) dla _p_ we wskazanym okresie czasu (np. dniu, miesiącu);
5.  Posortować wskazane okresy czasu (np. dni, miesiące)  w kolejności niemalejących/nierosnących wartości _p_;
6.  Zaprezentować dane w postaci histogramów o ilości przedziałów podanych przez użytkownika, np. dla danych [9, 1, 2, 4, 1, 3, 5,  6, 7, 8, 1, 2, 3, 9] i 3 przedziałów,
    histogram ma postać:

| przedział wartości danych  | <1,4)	| <4, 7)	 | <7,9>	|
|----------------------------|--------|----------|--------|
| liczba danych w przedziale | 7      | 3        | 4 		  |

8.  Na podstawie histogramów znaleźć przedział(y) o największej (albo najmniejszej) liczności.

**Uwaga:**  wszystkie funkcjonalności powinny być wykonywane dla każdego z wybranych 3 parametrów pogody (czyli dla każdej z trzech tablic). Program powinien być elegancko zorganizowany: każda funkcjonalność powinna mieć swoją funkcję przyjmującą tablicę jako parametr, w razie konieczności wykonania tej samej (bądź analogicznej) operacji na tablicach o elementach różnych typów, funkcja powinna zostać przeciążona. Powtórzenia tego samego kodu powinny zostać zminimalizowane (zgodnie ze zdobytą wiedzą).

