# Localmulti
Application Server/Client in C,  using Real-Time Streaming Protocol (RTSP) to enable Multiplayer in Rocksmith 2014 or in other games. 
Something like "Remote Play Together" of Steam or Parsec. 

![image](https://github.com/mayktu/localmulti/assets/38228656/2a2f7b45-511f-4c50-940c-106ff63fa65d){:height="36px" width="36px"}

![image](https://github.com/mayktu/localmulti/assets/38228656/b87cdd07-bbbe-4ef1-9eeb-1fce64bbe4fc){:height="36px" width="36px"}

![image](https://github.com/mayktu/localmulti/assets/38228656/bfeebd69-ffac-4610-877e-349f9a388219){:height="36px" width="36px"}



## Build and Run
```
docker build -t servidor-rtsp -f Dockerfile.prd
docker run -p 554:554 servidor-rtsp
```
