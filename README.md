# VillageGenerator
Simulate the generation of villages in minecraft  
Support for every type of village  
Versions supported for house locations: 1.14 1.15 1.16 1.17  
Versions supported for loot: 1.16 1.17  
I used Kaptain Wutax libraries and mojang code.   
Thank to Solver3002 for his help.  
Credit to Mojang and Kaptain Wutax and Neil for their librairies. I reused the start of their VillageGenerator.  


# Install Instructions
Add the following to your build.gradle repositories block
```    
    maven {url "https://jitpack.io"}
```
and the following to your build.gradle dependencies block:
```
    implementation('com.github.profotoce59:VillageGenerator:main-SNAPSHOT'){transitive=false}
```