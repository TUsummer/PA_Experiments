# PA_Experiments
---
## Pattern-Aware Cache Management Strategy
Project Pattern implements our novel Pattern-Aware cache management strategy. The file called Requests.csv in directory track is the simulation requests. We test the response time and cache hit ratio of these requests in our experiments.  
  
## 7 Comparison Experiments
There are 7 comparison experiments, including the direct method without SSD cache implemented in project NoCache, LRU policy applied both on full and sub FITS files, which are implemented in LRU\_ALL and LRU\_SUB respectively, LFU policy applied both on full and sub FITS files, which are implemented in LFU\_ALL and LFU\_SUB respectively, LRFU policy applied both on full and sub FITS files, which are implemented in LRFU\_ALL and LRFU\_SUB respectively.

## Notes
All these experiments are conducted in an environment with a cfitsio library. The latest version is always available from this link: http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/cfitsio_latest.tar.gz
