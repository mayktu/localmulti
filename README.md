# Localmulti
Application Server/Client in C,  using Real-Time Streaming Protocol (RTSP) to enable Multiplayer in Rocksmith 2014 or in other games. 
Something like "Remote Play Together" of Steam or Parsec. 


## Build and Run
```
docker build -t servidor-rtsp -f Dockerfile.prd
docker run -p 554:554 servidor-rtsp
```
