from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            name="repro",
            sources=["repro.c"],
        ),
    ]
)

