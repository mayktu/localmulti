# Localmulti
Application Server/Client in C,  using Real-Time Streaming Protocol (RTSP) to enable Multiplayer in Rocksmith 2014 or in other games. 
Something like "Remote Play Together" of Steam or Parsec. 

## Motivation
<img src="https://github.com/mayktu/localmulti/assets/38228656/2a2f7b45-511f-4c50-940c-106ff63fa65d" width="300" height="200" style="align:center;"/>

<img src="https://github.com/mayktu/localmulti/assets/38228656/b87cdd07-bbbe-4ef1-9eeb-1fce64bbe4fc" width="300" height="200" style="align:center;"/>

<img src="https://github.com/mayktu/localmulti/assets/38228656/bfeebd69-ffac-4610-877e-349f9a388219" width="300" height="200" style="align:center;"/>

## Build and Run
```
docker build -t servidor-rtsp -f Dockerfile.prd
docker run -p 554:554 servidor-rtsp
```
