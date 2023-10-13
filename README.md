# GodBolt_Examples
Learning examples in GodBolt

# CBuffer Alignment
In hlsl, cbuffers cannot cross the 16-byte boundary between members. If one member were to cross, it is simply moved to the next boundary. You need to make sure that your CPU side struct that you memcpy to the buffer follows this rule, the compiler wont do it for you!

# Template specializations
Find if a `type` exists in a param pack only using templates logic
```
template <typename T, typename... Ts>
struct IndexOf<T, TypePack<T, Ts...>> {

template <typename T, typename U, typename... Ts>
struct IndexOf<T, TypePack<U, Ts...>> {
// recurrsively call, after having stripped the top type off, add to count
```

IndexOf is called via `<type_you_want_to_serach_for, param_pack>`. The template specialization `<T, Typepack<T, Ts...>>` is a better fit than `<T, Typepack<U, Ts...>>` if they are the same type, as T remains constant
