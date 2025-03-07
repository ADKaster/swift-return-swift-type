import exe

func printThings()
{
    print("hello")
    let y = Optional.init(fromCxx: getValue())
    print(y!)
    let z = Optional.init(fromCxx: getString())
    print(z ?? "none")
    print(String(getAString()))
}

printThings()