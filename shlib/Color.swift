
import shlib

public func colorFromString(_ str: String) -> shlib.Color?
{
    if (str == "red") {
        return Color(1234)
    }
    return nil
}

func __forceMetadata() -> [shlib.Color]
{
    return [Color(1234)]
}

