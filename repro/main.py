import contextvars
import gc
import repro


ctx = contextvars.ContextVar("ctx", default=None)
o = object()
print(o)

ctx.set(o)
print(ctx.get())
del o
gc.collect()
print(ctx.get())

repro.decref(ctx.get())
print(ctx.get())
