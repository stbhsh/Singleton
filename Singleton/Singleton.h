//.h
#define Singleton_interface(class)\
+ (instancetype)shareInstance;
//.m
#if __has_feature(objc_arc)
//arc 下
#define Singleton_implementation(class)\
static class * _instance;\
\
- (instancetype)init{\
  self = [super init];\
  if(self){\
\
}\
  return self;\
}\
+ (instancetype)allocWithZone:(struct _NSZone*)zone{\
  static dispatch_once_t onceToken;\
         dispatch_once(&onceToken,^{\
        _instance = [super allocWithZone:zone];\
});\
  return _instance;\
}\
+ (instancetype)shareInstance{\
  if(_instance == nil){\
  _instance = [[super alloc] init];\
       }\
  return _instance;\
}\
- (id)copyWithZone:(NSZone*)zone{\
  return _instance;\
}\
- (id)mutableCopyWithZone:(NSZone*)zone{\
  return _instance;\
}
#else 
// mrc下
#define Singleton_implementation(class)\
static class * _instance;\
\
- (instancetype)init{\
self = [super init];\
if(self){\
\
}\
return self;\
}\
+ (instancetype)allocWithZone:(struct NSZone*)zone{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken,^{\
_instance = [super allocWithZone:zone];\
});\
return _instance;\
}\
+ (instancetype)shareInstance{\
if(_instance == nil){\
_instance = [[super alloc] init];\
}\
return _instance;\
}\
- (id)copyWithZone:(struct NSZone*)zone{\
return _instance;\
}\
- (id)mutableCopyWithZone:(struct NSZone*)zone{\
return _instance;\
}\
- (oneway void)release{\
}\
- (id)retain{\
return _instance;\
}\
- (id)retainCount{\
return ULONG_MAX;\
}\
- (id)autorelease{\
returen _instance;\
}
#endif