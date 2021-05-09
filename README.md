# Pulso con arduino

Este proyecto tiene como objetivo desarrollar un script que muestre una pulsación de frecuencia variable en el LED integrado en la placa arduino

## Características

- Luz del LED:
    - Parpadeo continuo 
    - El ritmo de parpadeo varia según una señal senoidal

## Decisiones
###### Frecuencias
- Se han probado diferentes valores hasta conseguir los deseados
- Frecuencia mínima:
    - Con un valor de 300 milisegundos
- Frecuencia máxima:
    - Con un valor de 1500 milisegundos

###### Periodo de la onda
- Se han probado distintos valores para obtener el comportamiento deseado
- Utilizamos el siguiente código para calcular el seno en cada ejecución del loop:

```c++
timer = sin(PI*(millis())/wave_period_time);
```

###### Función propia de mapeo
- La función map existente en arduino trabajaba con valores enteros, lo que no nos era válido para trabajar con los valores decimales del seno. Por ello se ha implementado la misma función que existe en arduino pero con parámetros float:

```c++
int override_map(float x, float in_min, float in_max, int out_min, int out_max) {
  return (int)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
```


## Herramientas utilizadas
- [Editar el readme.md](https://dillinger.io/)
- [Arduino](https://www.arduino.cc/)

## Referencias
- [Map](https://www.arduino.cc/reference/en/language/functions/math/map/)

## Realizado por 
- [José Juan Reyes Cabrera](https://github.com/JoseJuanRC)
- [Samuel Arrocha Quevedo](https://github.com/Samuel-AQ)
- [Anayara Moreno Merino](https://github.com/ana3311)
